// Constants
const STORAGE_KEY = 'sock-key-users';
const SENSOR_STORAGE_KEY = 'sock-key-sensors';
const ADMIN_PASSWORD = 'admin123';

// State
let users = [];
let sensorReadings = [];
let editingUser = null;
let deleteUserId = null;
let isAdminUnlocked = false;
let rfidScanning = false;
let rfidData = null;
let fingerprintEnrolling = false;
let fingerprintScans = 0;
let fingerprintData = null;
let activeTab = 'add-user';
let searchQuery = '';
let selectedSlot = null;
let popoverTarget = null;

// Initialize app
document.addEventListener('DOMContentLoaded', () => {
  loadData();
  initEventListeners();
  renderSensorPanel();
  renderUserList();
  updateSystemInfo();
  updateAdminBadge();
});

// Load data from localStorage
function loadData() {
  const storedUsers = localStorage.getItem(STORAGE_KEY);
  const storedSensors = localStorage.getItem(SENSOR_STORAGE_KEY);

  if (storedUsers) {
    try {
      users = JSON.parse(storedUsers);
    } catch (e) {
      console.error('Failed to load users', e);
    }
  }

  if (storedSensors) {
    try {
      sensorReadings = JSON.parse(storedSensors);
    } catch (e) {
      console.error('Failed to load sensor readings', e);
    }
  }
}

// Save data to localStorage
function saveUsers() {
  localStorage.setItem(STORAGE_KEY, JSON.stringify(users));
}

function saveSensorReadings() {
  const recentReadings = sensorReadings.slice(-50);
  localStorage.setItem(SENSOR_STORAGE_KEY, JSON.stringify(recentReadings));
}

// Event Listeners
function initEventListeners() {
  // Tabs
  document.querySelectorAll('.tab-trigger').forEach(tab => {
    tab.addEventListener('click', (e) => {
      switchTab(e.target.dataset.tab);
    });
  });

  // User Form
  document.getElementById('user-form').addEventListener('submit', handleUserFormSubmit);
  document.getElementById('cancel-btn').addEventListener('click', handleCancelEdit);

  // User Search
  document.getElementById('user-search').addEventListener('input', (e) => {
    searchQuery = e.target.value;
    renderUserList();
  });

  // Modals
  document.getElementById('confirm-cancel').addEventListener('click', closeConfirmDialog);
  document.getElementById('confirm-action').addEventListener('click', confirmDelete);
  document.getElementById('password-cancel').addEventListener('click', closePasswordDialog);
  document.getElementById('password-form').addEventListener('submit', handlePasswordSubmit);

  // Grid Modal
  document.getElementById('open-grid-btn').addEventListener('click', openGridModal);
  document.getElementById('grid-close').addEventListener('click', closeGridModal);
  document.getElementById('grid-search').addEventListener('input', (e) => {
    renderSlotGrid(e.target.value);
  });

  // Close modals on overlay click
  document.querySelectorAll('.modal-overlay').forEach(overlay => {
    overlay.addEventListener('click', (e) => {
      if (e.target === overlay) {
        closeAllModals();
      }
    });
  });

  // Sensor data pickers
  document.getElementById('rfid-picker-btn').addEventListener('click', (e) => {
    showSensorPicker(e.target, 'rfid');
  });
  document.getElementById('fingerprint-picker-btn').addEventListener('click', (e) => {
    showSensorPicker(e.target, 'fingerprint');
  });

  // Close popover when clicking outside
  document.addEventListener('click', (e) => {
    const popover = document.getElementById('sensor-picker-popover');
    const rfidBtn = document.getElementById('rfid-picker-btn');
    const fpBtn = document.getElementById('fingerprint-picker-btn');
    
    if (popover.style.display === 'block' && 
        !popover.contains(e.target) && 
        e.target !== rfidBtn && 
        e.target !== fpBtn &&
        !rfidBtn.contains(e.target) &&
        !fpBtn.contains(e.target)) {
      popover.style.display = 'none';
    }
  });
}

// Tab Switching
function switchTab(tabName) {
  activeTab = tabName;
  
  // Update tab triggers
  document.querySelectorAll('.tab-trigger').forEach(tab => {
    tab.classList.toggle('active', tab.dataset.tab === tabName);
  });

  // Update tab contents
  document.querySelectorAll('.tab-content').forEach(content => {
    content.classList.toggle('active', content.id === tabName);
  });

  // Render grid if switching to user list
  if (tabName === 'user-list') {
    renderUserList();
  }
}

// Sensor Panel
function renderSensorPanel() {
  renderRFIDSensor();
  renderFingerprintSensor();
  updateRecentScans();
}

function renderRFIDSensor() {
  const statusDiv = document.getElementById('rfid-status');
  
  if (rfidData) {
    statusDiv.innerHTML = `
      <div class="status-box success">
        <svg class="icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
          <path d="M22 11.08V12a10 10 0 1 1-5.93-9.14"/>
          <polyline points="22 4 12 14.01 9 11.01"/>
        </svg>
        <div class="status-text">
          <div class="status-title">Scan Successful</div>
          <div class="status-data">${rfidData}</div>
        </div>
      </div>
      <div style="display: flex; gap: 0.5rem;">
        <button class="btn btn-primary btn-sm flex-1" onclick="saveRFIDData()">
          <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <path d="M22 11.08V12a10 10 0 1 1-5.93-9.14"/>
            <polyline points="22 4 12 14.01 9 11.01"/>
          </svg>
          Save UID
        </button>
        <button class="btn btn-outline btn-sm" onclick="refreshRFID()">
          <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <polyline points="23 4 23 10 17 10"/>
            <polyline points="1 20 1 14 7 14"/>
            <path d="M3.51 9a9 9 0 0 1 14.85-3.36L23 10M1 14l4.64 4.36A9 9 0 0 0 20.49 15"/>
          </svg>
        </button>
      </div>
    `;
  } else if (rfidScanning) {
    statusDiv.innerHTML = `
      <div class="status-box scanning">
        <svg class="icon spin" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
          <line x1="12" y1="2" x2="12" y2="6"/>
          <line x1="12" y1="18" x2="12" y2="22"/>
          <line x1="4.93" y1="4.93" x2="7.76" y2="7.76"/>
          <line x1="16.24" y1="16.24" x2="19.07" y2="19.07"/>
          <line x1="2" y1="12" x2="6" y2="12"/>
          <line x1="18" y1="12" x2="22" y2="12"/>
          <line x1="4.93" y1="19.07" x2="7.76" y2="16.24"/>
          <line x1="16.24" y1="7.76" x2="19.07" y2="4.93"/>
        </svg>
        <div class="status-text">
          <div class="status-title">Scanning...</div>
        </div>
      </div>
      <div class="progress-bar">
        <div class="progress-fill" style="width: 50%;"></div>
      </div>
    `;
  } else {
    statusDiv.innerHTML = `
      <button class="btn btn-primary btn-full" onclick="startRFIDScan()">Start RFID Scan</button>
    `;
  }
}

function renderFingerprintSensor() {
  const statusDiv = document.getElementById('fingerprint-status');
  
  if (fingerprintData) {
    statusDiv.innerHTML = `
      <div class="status-box success">
        <svg class="icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
          <path d="M22 11.08V12a10 10 0 1 1-5.93-9.14"/>
          <polyline points="22 4 12 14.01 9 11.01"/>
        </svg>
        <div class="status-text">
          <div class="status-title">Enrollment Complete</div>
          <div class="status-data">${fingerprintData}</div>
        </div>
      </div>
      <div style="display: flex; gap: 0.5rem;">
        <button class="btn btn-primary btn-sm flex-1" onclick="saveFingerprintData()">
          <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <path d="M22 11.08V12a10 10 0 1 1-5.93-9.14"/>
            <polyline points="22 4 12 14.01 9 11.01"/>
          </svg>
          Save FID
        </button>
        <button class="btn btn-outline btn-sm" onclick="refreshFingerprint()">
          <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <polyline points="23 4 23 10 17 10"/>
            <polyline points="1 20 1 14 7 14"/>
            <path d="M3.51 9a9 9 0 0 1 14.85-3.36L23 10M1 14l4.64 4.36A9 9 0 0 0 20.49 15"/>
          </svg>
        </button>
      </div>
    `;
  } else if (fingerprintEnrolling) {
    const progress = (fingerprintScans / 4) * 100;
    statusDiv.innerHTML = `
      <div class="status-box scanning">
        <svg class="icon spin" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
          <line x1="12" y1="2" x2="12" y2="6"/>
          <line x1="12" y1="18" x2="12" y2="22"/>
          <line x1="4.93" y1="4.93" x2="7.76" y2="7.76"/>
          <line x1="16.24" y1="16.24" x2="19.07" y2="19.07"/>
          <line x1="2" y1="12" x2="6" y2="12"/>
          <line x1="18" y1="12" x2="22" y2="12"/>
          <line x1="4.93" y1="19.07" x2="7.76" y2="16.24"/>
          <line x1="16.24" y1="7.76" x2="19.07" y2="4.93"/>
        </svg>
        <div class="status-text">
          <div class="status-title">Enrolling...</div>
          <div class="status-data">Scan ${fingerprintScans} of 4</div>
        </div>
      </div>
      <div class="progress-bar">
        <div class="progress-fill" style="width: ${progress}%;"></div>
      </div>
    `;
  } else {
    statusDiv.innerHTML = `
      <button class="btn btn-primary btn-full" onclick="startFingerprintEnroll()">Start Enrollment</button>
    `;
  }
}

function updateRecentScans() {
  // RFID recent scans
  const rfidList = document.getElementById('rfid-recent-list');
  const rfidScans = sensorReadings.filter(r => r.type === 'rfid').slice(-3).reverse();
  
  if (rfidScans.length > 0) {
    rfidList.innerHTML = rfidScans.map(scan => 
      `<div class="recent-scan-item">${scan.data}</div>`
    ).join('');
  } else {
    rfidList.innerHTML = '<div class="no-scans">No scans yet</div>';
  }

  // Fingerprint recent scans
  const fpList = document.getElementById('fingerprint-recent-list');
  const fpScans = sensorReadings.filter(r => r.type === 'fingerprint').slice(-3).reverse();
  
  if (fpScans.length > 0) {
    fpList.innerHTML = fpScans.map(scan => 
      `<div class="recent-scan-item">${scan.data}</div>`
    ).join('');
  } else {
    fpList.innerHTML = '<div class="no-scans">No enrollments yet</div>';
  }

  // Update form displays if not editing
  if (!editingUser) {
    const latestRFID = sensorReadings.filter(r => r.type === 'rfid').slice(-1)[0];
    const latestFP = sensorReadings.filter(r => r.type === 'fingerprint').slice(-1)[0];
    
    const rfidValue = document.getElementById('rfid-value');
    const fpValue = document.getElementById('fingerprint-value');
    
    rfidValue.textContent = latestRFID ? latestRFID.data : 'Scan RFID card above';
    fpValue.textContent = latestFP ? latestFP.data : 'Enroll fingerprint above';
  }
}

// RFID Functions
function startRFIDScan() {
  rfidScanning = true;
  renderRFIDSensor();
  
  setTimeout(() => {
    rfidData = generateRFIDUID();
    rfidScanning = false;
    renderRFIDSensor();
  }, 2000);
}

function saveRFIDData() {
  if (rfidData) {
    sensorReadings.push({
      type: 'rfid',
      data: rfidData,
      timestamp: Date.now()
    });
    saveSensorReadings();
    rfidData = null;
    renderSensorPanel();
    updateSystemInfo();
    showToast('RFID UID saved successfully', 'success');
  }
}

function refreshRFID() {
  rfidData = null;
  startRFIDScan();
}

// Fingerprint Functions
function startFingerprintEnroll() {
  fingerprintEnrolling = true;
  fingerprintScans = 0;
  fingerprintData = null;
  renderFingerprintSensor();
  
  const enrollmentId = generateFingerprintID();
  
  const scanInterval = setInterval(() => {
    fingerprintScans++;
    renderFingerprintSensor();
    
    if (fingerprintScans >= 4) {
      clearInterval(scanInterval);
      fingerprintEnrolling = false;
      fingerprintData = enrollmentId;
      renderFingerprintSensor();
    }
  }, 1500);
}

function saveFingerprintData() {
  if (fingerprintData) {
    sensorReadings.push({
      type: 'fingerprint',
      data: fingerprintData,
      timestamp: Date.now()
    });
    saveSensorReadings();
    fingerprintData = null;
    fingerprintScans = 0;
    renderSensorPanel();
    updateSystemInfo();
    showToast('Fingerprint ID saved successfully', 'success');
  }
}

function refreshFingerprint() {
  fingerprintData = null;
  fingerprintScans = 0;
  startFingerprintEnroll();
}

// Generate sensor data
function generateRFIDUID() {
  const bytes = Array.from({ length: 4 }, () => 
    Math.floor(Math.random() * 256).toString(16).padStart(2, '0')
  );
  return bytes.join(':').toUpperCase();
}

function generateFingerprintID() {
  const id = Math.floor(Math.random() * 65536);
  return `FP${id.toString(16).toUpperCase().padStart(4, '0')}`;
}

// User Form
function handleUserFormSubmit(e) {
  e.preventDefault();
  
  const name = document.getElementById('user-name').value.trim();
  const idSlot = parseInt(document.getElementById('user-slot').value);
  const rfidUID = document.getElementById('rfid-value').textContent;
  const fingerprintID = document.getElementById('fingerprint-value').textContent;
  const isAdmin = document.getElementById('user-admin').checked;

  // Validation
  if (!name || !idSlot) {
    showToast('Please fill in all required fields', 'error');
    return;
  }

  const rfidValid = rfidUID && rfidUID !== 'Scan RFID card above';
  const fpValid = fingerprintID && fingerprintID !== 'Enroll fingerprint above';

  if (!rfidValid && !fpValid) {
    showToast('Please provide at least RFID UID or Fingerprint ID', 'error');
    return;
  }

  if (idSlot < 1 || idSlot > 100) {
    showToast('ID Slot must be between 1 and 100', 'error');
    return;
  }

  // Check if slot is available
  const slotTaken = users.some(u => u.idSlot === idSlot && (!editingUser || u.id !== editingUser.id));
  if (slotTaken) {
    showToast('This ID slot is already taken', 'error');
    return;
  }

  // Save user
  if (editingUser) {
    const index = users.findIndex(u => u.id === editingUser.id);
    users[index] = {
      ...editingUser,
      name,
      idSlot,
      rfidUID: rfidValid ? rfidUID : undefined,
      fingerprintID: fpValid ? fingerprintID : undefined,
      isAdmin
    };
    showToast('User updated successfully', 'success');
    editingUser = null;
    switchTab('user-list');
  } else {
    users.push({
      id: Date.now().toString(),
      name,
      idSlot,
      rfidUID: rfidValid ? rfidUID : undefined,
      fingerprintID: fpValid ? fingerprintID : undefined,
      isAdmin,
      createdAt: Date.now()
    });
    showToast('User added successfully', 'success');
  }

  saveUsers();
  resetForm();
  renderUserList();
  updateSystemInfo();
}

function resetForm() {
  document.getElementById('user-form').reset();
  document.getElementById('user-name').value = '';
  document.getElementById('user-slot').value = '';
  document.getElementById('user-admin').checked = false;
  
  // Reset displays
  const latestRFID = sensorReadings.filter(r => r.type === 'rfid').slice(-1)[0];
  const latestFP = sensorReadings.filter(r => r.type === 'fingerprint').slice(-1)[0];
  
  document.getElementById('rfid-value').textContent = latestRFID ? latestRFID.data : 'Scan RFID card above';
  document.getElementById('fingerprint-value').textContent = latestFP ? latestFP.data : 'Enroll fingerprint above';
  
  // Hide picker buttons and cancel button
  document.getElementById('rfid-picker-container').style.display = 'none';
  document.getElementById('fingerprint-picker-container').style.display = 'none';
  document.getElementById('cancel-btn').style.display = 'none';
  
  // Update form title and submit button
  document.getElementById('form-title').textContent = 'Add New User';
  document.getElementById('tab-add-label').textContent = 'Add User';
  document.getElementById('submit-btn').textContent = 'Add User';
}

function handleCancelEdit() {
  editingUser = null;
  resetForm();
  switchTab('user-list');
}

// Edit User
function editUser(userId) {
  const user = users.find(u => u.id === userId);
  if (!user) return;

  // Check if user has admin privileges
  if (user.isAdmin && !isAdminUnlocked) {
    editingUser = user;
    openPasswordDialog();
  } else {
    startEditingUser(user);
  }
}

function startEditingUser(user) {
  editingUser = user;
  
  // Fill form
  document.getElementById('user-name').value = user.name;
  document.getElementById('user-slot').value = user.idSlot;
  document.getElementById('user-admin').checked = user.isAdmin;
  
  // Fill sensor data
  document.getElementById('rfid-value').textContent = user.rfidUID || 'Not set';
  document.getElementById('fingerprint-value').textContent = user.fingerprintID || 'Not set';
  
  // Show picker buttons and cancel button
  document.getElementById('rfid-picker-container').style.display = 'block';
  document.getElementById('fingerprint-picker-container').style.display = 'block';
  document.getElementById('cancel-btn').style.display = 'block';
  
  // Update form title and submit button
  document.getElementById('form-title').textContent = 'Edit User';
  document.getElementById('tab-add-label').textContent = 'Edit User';
  document.getElementById('submit-btn').textContent = 'Update User';
  
  switchTab('add-user');
}

// Delete User
function deleteUser(userId) {
  deleteUserId = userId;
  const user = users.find(u => u.id === userId);
  
  document.getElementById('confirm-title').textContent = 'Delete User';
  document.getElementById('confirm-description').textContent = 
    `Are you sure you want to delete ${user?.name}? This action cannot be undone.`;
  
  document.getElementById('confirm-dialog').style.display = 'flex';
}

function confirmDelete() {
  if (deleteUserId) {
    users = users.filter(u => u.id !== deleteUserId);
    saveUsers();
    showToast('User deleted successfully', 'success');
    deleteUserId = null;
    
    if (editingUser?.id === deleteUserId) {
      editingUser = null;
      resetForm();
    }
    
    renderUserList();
    updateSystemInfo();
  }
  closeConfirmDialog();
}

// User List
function renderUserList() {
  const listContainer = document.getElementById('user-list-items');
  const userCount = document.getElementById('user-count');
  
  userCount.textContent = users.length;

  const filteredUsers = users.filter(user =>
    user.name.toLowerCase().includes(searchQuery.toLowerCase()) ||
    user.idSlot.toString().includes(searchQuery)
  );

  if (filteredUsers.length === 0) {
    listContainer.innerHTML = '<div class="no-users">No users found</div>';
    return;
  }

  listContainer.innerHTML = filteredUsers.map(user => `
    <div class="user-item">
      <div class="user-info">
        <div class="user-header">
          <h4 class="user-name">${escapeHtml(user.name)}</h4>
          ${user.isAdmin ? `
            <div class="badge badge-outline">
              <svg class="icon-xs" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                <path d="M12 22s8-4 8-10V5l-8-3-8 3v7c0 6 8 10 8 10z"/>
              </svg>
              Admin
            </div>
          ` : ''}
        </div>
        <div class="user-details">
          <div class="user-detail">
            <span class="user-id-badge">ID: ${user.idSlot}</span>
          </div>
          ${user.rfidUID ? `
            <div class="user-detail">
              <svg class="icon-xs" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                <rect x="1" y="4" width="22" height="16" rx="2" ry="2"/>
                <line x1="1" y1="10" x2="23" y2="10"/>
              </svg>
              <span>${user.rfidUID}</span>
            </div>
          ` : ''}
          ${user.fingerprintID ? `
            <div class="user-detail">
              <svg class="icon-xs" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                <path d="M12 10a2 2 0 0 0-2 2c0 1.02-.1 2.51-.26 4"/>
                <path d="M14 13.12c0 2.38 0 6.38-1 8.88"/>
                <path d="M17.29 21.02c.12-.6.43-2.3.5-3.02"/>
                <path d="M2 12a10 10 0 0 1 18-6"/>
                <path d="M2 16h.01"/>
                <path d="M21.8 16c.2-2 .131-5.354 0-6"/>
                <path d="M5 19.5C5.5 18 6 15 6 12a6 6 0 0 1 .34-2"/>
                <path d="M8.65 22c.21-.66.45-1.32.57-2"/>
                <path d="M9 6.8a6 6 0 0 1 9 5.2v2"/>
              </svg>
              <span>${user.fingerprintID}</span>
            </div>
          ` : ''}
        </div>
      </div>
      <div class="user-actions">
        <button class="icon-btn" onclick="editUser('${user.id}')" title="Edit">
          <svg class="icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <path d="M11 4H4a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h14a2 2 0 0 0 2-2v-7"/>
            <path d="M18.5 2.5a2.121 2.121 0 0 1 3 3L12 15l-4 1 1-4 9.5-9.5z"/>
          </svg>
        </button>
        <button class="icon-btn destructive" onclick="deleteUser('${user.id}')" title="Delete">
          <svg class="icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <polyline points="3 6 5 6 21 6"/>
            <path d="M19 6v14a2 2 0 0 1-2 2H7a2 2 0 0 1-2-2V6m3 0V4a2 2 0 0 1 2-2h4a2 2 0 0 1 2 2v2"/>
          </svg>
        </button>
      </div>
    </div>
  `).join('');
}

// System Info
function updateSystemInfo() {
  document.getElementById('info-registered').textContent = users.length;
  document.getElementById('info-available').textContent = 100 - users.length;
  document.getElementById('info-admins').textContent = users.filter(u => u.isAdmin).length;
  document.getElementById('info-sensors').textContent = sensorReadings.length;
}

// Admin Badge
function updateAdminBadge() {
  const badge = document.getElementById('admin-badge');
  const status = document.getElementById('admin-status');
  
  if (isAdminUnlocked) {
    badge.classList.add('badge-primary');
    badge.innerHTML = `
      <svg class="badge-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
        <rect x="3" y="11" width="18" height="11" rx="2" ry="2"/>
        <path d="M7 11V7a5 5 0 0 1 9.9-1"/>
      </svg>
      <span>Admin Access</span>
    `;
  } else {
    badge.classList.remove('badge-primary');
    badge.innerHTML = `
      <svg class="badge-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
        <rect x="3" y="11" width="18" height="11" rx="2" ry="2"/>
        <path d="M7 11V7a5 5 0 0 1 10 0v4"/>
      </svg>
      <span>Standard Access</span>
    `;
  }
}

// Modals
function closeConfirmDialog() {
  document.getElementById('confirm-dialog').style.display = 'none';
  deleteUserId = null;
}

function openPasswordDialog() {
  document.getElementById('password-dialog').style.display = 'flex';
  setTimeout(() => {
    document.getElementById('admin-password').focus();
  }, 100);
}

function closePasswordDialog() {
  document.getElementById('password-dialog').style.display = 'none';
  document.getElementById('admin-password').value = '';
  document.getElementById('password-error').style.display = 'none';
  editingUser = null;
}

function handlePasswordSubmit(e) {
  e.preventDefault();
  const password = document.getElementById('admin-password').value;
  
  if (password === ADMIN_PASSWORD) {
    isAdminUnlocked = true;
    updateAdminBadge();
    showToast('Administrator access granted', 'success');
    closePasswordDialog();
    
    if (editingUser) {
      startEditingUser(editingUser);
    }
  } else {
    document.getElementById('password-error').style.display = 'block';
  }
}

function closeAllModals() {
  document.getElementById('confirm-dialog').style.display = 'none';
  document.getElementById('password-dialog').style.display = 'none';
  document.getElementById('grid-modal').style.display = 'none';
  document.getElementById('sensor-picker-popover').style.display = 'none';
}

// Grid Modal
function openGridModal() {
  document.getElementById('grid-modal').style.display = 'flex';
  document.getElementById('grid-search').value = '';
  selectedSlot = null;
  renderSlotGrid('');
}

function closeGridModal() {
  document.getElementById('grid-modal').style.display = 'none';
  selectedSlot = null;
}

function renderSlotGrid(search = '') {
  const gridContainer = document.getElementById('slot-grid');
  const slots = Array.from({ length: 100 }, (_, i) => i + 1);
  
  // Create user map
  const usersBySlot = new Map();
  users.forEach(user => {
    usersBySlot.set(user.idSlot, user);
  });

  // Filter slots if search query exists
  const filteredSlots = search 
    ? slots.filter(slot => {
        const user = usersBySlot.get(slot);
        return user && (
          user.name.toLowerCase().includes(search.toLowerCase()) ||
          user.idSlot.toString().includes(search)
        );
      })
    : slots;

  gridContainer.innerHTML = (search ? filteredSlots : slots).map(slot => {
    const user = usersBySlot.get(slot);
    const isOccupied = !!user;
    const isSelected = selectedSlot === slot;
    
    return `
      <button 
        class="slot-btn ${isOccupied ? 'occupied' : 'available'} ${isSelected ? 'selected' : ''}"
        onclick="selectSlot(${slot})"
        title="${user ? user.name : `Slot ${slot} - Available`}"
      >
        ${slot}
      </button>
    `;
  }).join('');
}

function selectSlot(slot) {
  selectedSlot = slot;
  renderSlotGrid(document.getElementById('grid-search').value);
  
  const user = users.find(u => u.idSlot === slot);
  const infoDiv = document.getElementById('slot-info');
  const titleDiv = document.getElementById('slot-info-title');
  const contentDiv = document.getElementById('slot-info-content');
  
  infoDiv.style.display = 'block';
  titleDiv.textContent = `Slot ${slot} - ${user ? 'Occupied' : 'Available'}`;
  
  if (user) {
    contentDiv.innerHTML = `
      <div class="slot-info-content">
        <div class="slot-user-info">
          <div class="slot-user-header">
            <h4 class="slot-user-name">${escapeHtml(user.name)}</h4>
            ${user.isAdmin ? `
              <div class="badge badge-outline">
                <svg class="icon-xs" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                  <path d="M12 22s8-4 8-10V5l-8-3-8 3v7c0 6 8 10 8 10z"/>
                </svg>
                Admin
              </div>
            ` : ''}
          </div>
          ${user.rfidUID ? `
            <div class="slot-user-detail">
              <svg class="icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                <rect x="1" y="4" width="22" height="16" rx="2" ry="2"/>
                <line x1="1" y1="10" x2="23" y2="10"/>
              </svg>
              <span>${user.rfidUID}</span>
            </div>
          ` : ''}
          ${user.fingerprintID ? `
            <div class="slot-user-detail">
              <svg class="icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                <path d="M12 10a2 2 0 0 0-2 2c0 1.02-.1 2.51-.26 4"/>
                <path d="M14 13.12c0 2.38 0 6.38-1 8.88"/>
                <path d="M17.29 21.02c.12-.6.43-2.3.5-3.02"/>
                <path d="M2 12a10 10 0 0 1 18-6"/>
                <path d="M2 16h.01"/>
                <path d="M21.8 16c.2-2 .131-5.354 0-6"/>
                <path d="M5 19.5C5.5 18 6 15 6 12a6 6 0 0 1 .34-2"/>
                <path d="M8.65 22c.21-.66.45-1.32.57-2"/>
                <path d="M9 6.8a6 6 0 0 1 9 5.2v2"/>
              </svg>
              <span>${user.fingerprintID}</span>
            </div>
          ` : ''}
        </div>
        <div class="slot-actions">
          <button class="btn btn-outline btn-sm flex-1" onclick="editUserFromGrid('${user.id}')">
            <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
              <path d="M11 4H4a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h14a2 2 0 0 0 2-2v-7"/>
              <path d="M18.5 2.5a2.121 2.121 0 0 1 3 3L12 15l-4 1 1-4 9.5-9.5z"/>
            </svg>
            Edit
          </button>
          <button class="btn btn-destructive btn-sm flex-1" onclick="deleteUserFromGrid('${user.id}')">
            <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
              <polyline points="3 6 5 6 21 6"/>
              <path d="M19 6v14a2 2 0 0 1-2 2H7a2 2 0 0 1-2-2V6m3 0V4a2 2 0 0 1 2-2h4a2 2 0 0 1 2 2v2"/>
            </svg>
            Delete
          </button>
        </div>
      </div>
    `;
  } else {
    contentDiv.innerHTML = '<div class="slot-available">This slot is available</div>';
  }
}

function editUserFromGrid(userId) {
  closeGridModal();
  editUser(userId);
}

function deleteUserFromGrid(userId) {
  deleteUser(userId);
  selectedSlot = null;
}

// Sensor Data Picker
function showSensorPicker(button, type) {
  const popover = document.getElementById('sensor-picker-popover');
  const content = document.getElementById('popover-content');
  
  popoverTarget = type;
  
  const recentReadings = sensorReadings
    .filter(r => r.type === type)
    .slice(-3)
    .reverse();

  const currentValue = type === 'rfid' 
    ? document.getElementById('rfid-value').textContent
    : document.getElementById('fingerprint-value').textContent;

  if (recentReadings.length > 0) {
    content.innerHTML = recentReadings.map(reading => `
      <button 
        class="popover-item ${currentValue === reading.data ? 'selected' : ''}"
        onclick="selectSensorData('${type}', '${reading.data}')"
      >
        <svg class="icon-xs" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
          <circle cx="12" cy="12" r="10"/>
          <polyline points="12 6 12 12 16 14"/>
        </svg>
        ${reading.data}
      </button>
    `).join('');
  } else {
    content.innerHTML = '<div class="popover-empty">No recent scans available</div>';
  }

  // Position popover
  const rect = button.getBoundingClientRect();
  popover.style.top = `${rect.bottom + 5}px`;
  popover.style.left = `${rect.left}px`;
  popover.style.display = 'block';
}

function selectSensorData(type, data) {
  if (type === 'rfid') {
    document.getElementById('rfid-value').textContent = data;
  } else {
    document.getElementById('fingerprint-value').textContent = data;
  }
  
  document.getElementById('sensor-picker-popover').style.display = 'none';
}

// Toast
function showToast(message, type = 'success') {
  const container = document.getElementById('toast-container');
  const toast = document.createElement('div');
  toast.className = `toast ${type}`;
  
  const icon = type === 'success' 
    ? `<svg class="toast-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
         <path d="M22 11.08V12a10 10 0 1 1-5.93-9.14"/>
         <polyline points="22 4 12 14.01 9 11.01"/>
       </svg>`
    : `<svg class="toast-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
         <circle cx="12" cy="12" r="10"/>
         <line x1="12" y1="8" x2="12" y2="12"/>
         <line x1="12" y1="16" x2="12.01" y2="16"/>
       </svg>`;
  
  toast.innerHTML = `
    ${icon}
    <div class="toast-message">${escapeHtml(message)}</div>
  `;
  
  container.appendChild(toast);
  
  setTimeout(() => {
    toast.style.opacity = '0';
    toast.style.transform = 'translateX(400px)';
    setTimeout(() => {
      container.removeChild(toast);
    }, 300);
  }, 3000);
}

// Utility function to escape HTML
function escapeHtml(text) {
  const map = {
    '&': '&amp;',
    '<': '&lt;',
    '>': '&gt;',
    '"': '&quot;',
    "'": '&#039;'
  };
  return text.replace(/[&<>"']/g, m => map[m]);
}
