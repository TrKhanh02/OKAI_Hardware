// State Management
const ADMIN_PASSWORD = 'admin123';
let users = [];
let sensorReadings = [];
let currentSensorData = { uid: null, fid: null };
let editingUser = null;
let currentIdSlot = 1;
let currentSensorHistoryType = null;
let deleteUserId = null;
let pendingAdminState = false;

// Initialize
document.addEventListener('DOMContentLoaded', () => {
    loadFromLocalStorage();
    initializeEventListeners();
    renderUserList();
    renderIdGrid();
    updateCounts();
});

// Local Storage
function loadFromLocalStorage() {
    const savedUsers = localStorage.getItem('smartlock-users');
    const savedReadings = localStorage.getItem('smartlock-readings');
    
    if (savedUsers) {
        users = JSON.parse(savedUsers);
    }
    
    if (savedReadings) {
        sensorReadings = JSON.parse(savedReadings);
    }
}

function saveToLocalStorage() {
    localStorage.setItem('smartlock-users', JSON.stringify(users));
    localStorage.setItem('smartlock-readings', JSON.stringify(sensorReadings));
}

// Event Listeners
function initializeEventListeners() {
    // RFID Scanner
    document.getElementById('rfid-scan-btn').addEventListener('click', startRfidScan);
    document.getElementById('rfid-save-btn').addEventListener('click', saveRfidData);
    document.getElementById('rfid-refresh-btn').addEventListener('click', refreshRfid);
    
    // Fingerprint Scanner
    document.getElementById('fingerprint-enroll-btn').addEventListener('click', startFingerprintEnroll);
    document.getElementById('fingerprint-save-btn').addEventListener('click', saveFingerprintData);
    document.getElementById('fingerprint-refresh-btn').addEventListener('click', refreshFingerprint);
    
    // User Form
    document.getElementById('user-form').addEventListener('submit', handleFormSubmit);
    document.getElementById('form-cancel-btn').addEventListener('click', cancelEdit);
    document.getElementById('user-id-slot').addEventListener('input', handleIdSlotChange);
    document.getElementById('user-admin').addEventListener('change', handleAdminToggle);
    
    // Sensor History
    document.getElementById('rfid-history-btn').addEventListener('click', () => openSensorHistory('rfid'));
    document.getElementById('fingerprint-history-btn').addEventListener('click', () => openSensorHistory('fingerprint'));
    document.getElementById('close-sensor-history-modal').addEventListener('click', closeSensorHistory);
    
    // ID Grid
    document.getElementById('open-id-grid-btn').addEventListener('click', openIdGrid);
    document.getElementById('close-id-grid-modal').addEventListener('click', closeIdGrid);
    document.getElementById('grid-search-btn').addEventListener('click', searchInGrid);
    document.getElementById('grid-search').addEventListener('input', handleGridSearchInput);
    document.getElementById('grid-search-clear').addEventListener('click', clearGridSearch);
    document.getElementById('grid-search').addEventListener('keypress', (e) => {
        if (e.key === 'Enter') searchInGrid();
    });
    
    // User Search
    document.getElementById('user-search').addEventListener('input', handleUserSearch);
    
    // Admin Auth
    document.getElementById('admin-auth-form').addEventListener('submit', handleAdminAuth);
    document.getElementById('admin-auth-cancel').addEventListener('click', closeAdminAuth);
    document.getElementById('close-admin-auth-modal').addEventListener('click', closeAdminAuth);
    
    // Delete Confirmation
    document.getElementById('delete-confirm').addEventListener('click', confirmDelete);
    document.getElementById('delete-cancel').addEventListener('click', closeDeleteConfirmation);
    document.getElementById('close-delete-modal').addEventListener('click', closeDeleteConfirmation);
    
    // Modal Background Click
    document.querySelectorAll('.modal').forEach(modal => {
        modal.addEventListener('click', (e) => {
            if (e.target === modal) {
                modal.classList.remove('active');
            }
        });
    });
}

// RFID Scanner Functions
let rfidScanning = false;
let rfidData = null;

function startRfidScan() {
    rfidScanning = true;
    const scanBtn = document.getElementById('rfid-scan-btn');
    scanBtn.disabled = true;
    scanBtn.innerHTML = `
        <div class="spinner"></div>
        Scanning...
    `;
    
    setTimeout(() => {
        rfidData = Math.random().toString(16).substring(2, 10).toUpperCase();
        rfidScanning = false;
        
        document.getElementById('rfid-data-value').textContent = rfidData;
        document.getElementById('rfid-data-display').style.display = 'block';
        document.getElementById('rfid-action-buttons').style.display = 'flex';
        scanBtn.style.display = 'none';
    }, 2000);
}

function saveRfidData() {
    currentSensorData.uid = rfidData;
    
    // Add to sensor readings
    sensorReadings.unshift({
        uid: rfidData,
        fid: null,
        timestamp: Date.now()
    });
    sensorReadings = sensorReadings.slice(0, 20);
    saveToLocalStorage();
    
    // Update form field
    document.getElementById('user-rfid').value = rfidData;
    
    showToast('RFID UID saved successfully', 'success');
}

function refreshRfid() {
    rfidData = null;
    document.getElementById('rfid-data-display').style.display = 'none';
    document.getElementById('rfid-action-buttons').style.display = 'none';
    document.getElementById('rfid-scan-btn').style.display = 'block';
    document.getElementById('rfid-scan-btn').disabled = false;
    document.getElementById('rfid-scan-btn').innerHTML = 'Activate Scan';
    startRfidScan();
}

// Fingerprint Scanner Functions
let fingerprintScanning = false;
let fingerprintScans = 0;
let fingerprintData = null;
let fingerprintInterval = null;

function startFingerprintEnroll() {
    fingerprintScanning = true;
    fingerprintScans = 0;
    fingerprintData = null;
    
    const enrollBtn = document.getElementById('fingerprint-enroll-btn');
    enrollBtn.disabled = true;
    
    document.getElementById('fingerprint-scanning-display').style.display = 'flex';
    
    fingerprintInterval = setInterval(() => {
        fingerprintScans++;
        document.getElementById('fingerprint-scan-count').textContent = fingerprintScans;
        
        if (fingerprintScans >= 4) {
            clearInterval(fingerprintInterval);
            completeFingerprintEnroll();
        }
    }, 1500);
}

function completeFingerprintEnroll() {
    fingerprintScanning = false;
    
    // Generate FID that matches the target ID slot
    const targetSlot = editingUser ? editingUser.id : currentIdSlot;
    const slotHex = targetSlot.toString(16).padStart(2, '0').toUpperCase();
    const randomPart = Math.random().toString(16).substring(2, 8).toUpperCase();
    fingerprintData = slotHex + randomPart;
    
    document.getElementById('fingerprint-scanning-display').style.display = 'none';
    document.getElementById('fingerprint-data-value').textContent = fingerprintData;
    document.getElementById('fingerprint-data-display').style.display = 'block';
    document.getElementById('fingerprint-action-buttons').style.display = 'flex';
    document.getElementById('fingerprint-enroll-btn').style.display = 'none';
}

function saveFingerprintData() {
    currentSensorData.fid = fingerprintData;
    
    // Add to sensor readings
    sensorReadings.unshift({
        uid: null,
        fid: fingerprintData,
        timestamp: Date.now()
    });
    sensorReadings = sensorReadings.slice(0, 20);
    saveToLocalStorage();
    
    // Update form field
    document.getElementById('user-fingerprint').value = fingerprintData;
    
    showToast('Fingerprint FID saved successfully', 'success');
}

function refreshFingerprint() {
    fingerprintData = null;
    fingerprintScans = 0;
    
    if (fingerprintInterval) {
        clearInterval(fingerprintInterval);
    }
    
    document.getElementById('fingerprint-scanning-display').style.display = 'none';
    document.getElementById('fingerprint-data-display').style.display = 'none';
    document.getElementById('fingerprint-action-buttons').style.display = 'none';
    document.getElementById('fingerprint-enroll-btn').style.display = 'block';
    document.getElementById('fingerprint-enroll-btn').disabled = false;
    
    startFingerprintEnroll();
}

// User Form Functions
function handleFormSubmit(e) {
    e.preventDefault();
    
    const name = document.getElementById('user-name').value.trim();
    const idSlot = parseInt(document.getElementById('user-id-slot').value);
    const rfidUid = document.getElementById('user-rfid').value;
    const fingerprintFid = document.getElementById('user-fingerprint').value;
    const isAdmin = document.getElementById('user-admin').checked;
    
    if (!name || !idSlot) {
        showToast('Please fill in all required fields', 'error');
        return;
    }
    
    if (editingUser) {
        updateUser({ id: editingUser.id, name, rfidUid, fingerprintFid, isAdmin });
    } else {
        addUser({ id: idSlot, name, rfidUid, fingerprintFid, isAdmin });
    }
}

function addUser(userData) {
    // Check if ID slot is already taken
    const existingUser = users.find(u => u.id === userData.id);
    if (existingUser) {
        showToast(`ID slot ${userData.id} is already taken by ${existingUser.name}`, 'error');
        return;
    }
    
    // Validate FID matches ID slot
    if (userData.fingerprintFid) {
        const fidNumber = parseInt(userData.fingerprintFid.substring(0, 2), 16);
        if (fidNumber !== userData.id) {
            showToast(`FID must match ID slot ${userData.id}`, 'error');
            return;
        }
    }
    
    users.push(userData);
    saveToLocalStorage();
    
    showToast(`User "${userData.name}" added successfully`, 'success');
    
    resetForm();
    resetSensorPanel();
    renderUserList();
    renderIdGrid();
    updateCounts();
}

function updateUser(userData) {
    const index = users.findIndex(u => u.id === userData.id);
    if (index !== -1) {
        users[index] = { ...users[index], ...userData };
        saveToLocalStorage();
        
        showToast(`User "${userData.name}" updated successfully`, 'success');
        
        editingUser = null;
        resetForm();
        resetSensorPanel();
        renderUserList();
        renderIdGrid();
        updateCounts();
    }
}

function editUser(user) {
    editingUser = user;
    
    document.getElementById('user-name').value = user.name;
    document.getElementById('user-id-slot').value = user.id;
    document.getElementById('user-id-slot').disabled = true;
    document.getElementById('user-rfid').value = user.rfidUid || '';
    document.getElementById('user-fingerprint').value = user.fingerprintFid || '';
    document.getElementById('user-admin').checked = user.isAdmin || false;
    
    document.getElementById('form-title').innerHTML = `
        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <path d="M19 21H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h11l5 5v11a2 2 0 0 1-2 2z"></path>
            <polyline points="17 21 17 13 7 13 7 21"></polyline>
            <polyline points="7 3 7 8 15 8"></polyline>
        </svg>
        Edit User
    `;
    document.getElementById('form-submit-btn').innerHTML = `
        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <path d="M19 21H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h11l5 5v11a2 2 0 0 1-2 2z"></path>
            <polyline points="17 21 17 13 7 13 7 21"></polyline>
            <polyline points="7 3 7 8 15 8"></polyline>
        </svg>
        Save Changes
    `;
    document.getElementById('form-cancel-btn').style.display = 'flex';
    
    currentIdSlot = user.id;
    
    // Scroll to form
    setTimeout(() => {
        document.getElementById('user-form-section').scrollIntoView({ 
            behavior: 'smooth', 
            block: 'start' 
        });
    }, 100);
}

function cancelEdit() {
    editingUser = null;
    resetForm();
}

function resetForm() {
    document.getElementById('user-form').reset();
    document.getElementById('user-id-slot').disabled = false;
    document.getElementById('form-title').innerHTML = `
        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <path d="M16 21v-2a4 4 0 0 0-4-4H5a4 4 0 0 0-4 4v2"></path>
            <circle cx="8.5" cy="7" r="4"></circle>
            <line x1="20" y1="8" x2="20" y2="14"></line>
            <line x1="23" y1="11" x2="17" y2="11"></line>
        </svg>
        Add New User
    `;
    document.getElementById('form-submit-btn').innerHTML = `
        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
            <path d="M19 21H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h11l5 5v11a2 2 0 0 1-2 2z"></path>
            <polyline points="17 21 17 13 7 13 7 21"></polyline>
            <polyline points="7 3 7 8 15 8"></polyline>
        </svg>
        Add User
    `;
    document.getElementById('form-cancel-btn').style.display = 'none';
    
    currentSensorData = { uid: null, fid: null };
}

function resetSensorPanel() {
    // Reset RFID
    rfidData = null;
    document.getElementById('rfid-data-display').style.display = 'none';
    document.getElementById('rfid-action-buttons').style.display = 'none';
    document.getElementById('rfid-scan-btn').style.display = 'block';
    document.getElementById('rfid-scan-btn').disabled = false;
    document.getElementById('rfid-scan-btn').innerHTML = 'Activate Scan';
    
    // Reset Fingerprint
    fingerprintData = null;
    fingerprintScans = 0;
    if (fingerprintInterval) {
        clearInterval(fingerprintInterval);
    }
    document.getElementById('fingerprint-scanning-display').style.display = 'none';
    document.getElementById('fingerprint-data-display').style.display = 'none';
    document.getElementById('fingerprint-action-buttons').style.display = 'none';
    document.getElementById('fingerprint-enroll-btn').style.display = 'block';
    document.getElementById('fingerprint-enroll-btn').disabled = false;
}

function handleIdSlotChange(e) {
    currentIdSlot = parseInt(e.target.value) || 1;
}

function handleAdminToggle(e) {
    pendingAdminState = e.target.checked;
    e.target.checked = editingUser ? editingUser.isAdmin : false; // Revert until authenticated
    openAdminAuth();
}

// Delete User
function deleteUser(userId) {
    const user = users.find(u => u.id === userId);
    if (!user) return;
    
    deleteUserId = userId;
    document.getElementById('delete-confirmation-message').textContent = 
        `Are you sure you want to delete "${user.name}"? This action cannot be undone.`;
    document.getElementById('delete-confirmation-modal').classList.add('active');
}

function confirmDelete() {
    users = users.filter(u => u.id !== deleteUserId);
    saveToLocalStorage();
    
    const user = users.find(u => u.id === deleteUserId);
    showToast(`User deleted successfully`, 'success');
    
    if (editingUser && editingUser.id === deleteUserId) {
        cancelEdit();
    }
    
    closeDeleteConfirmation();
    renderUserList();
    renderIdGrid();
    updateCounts();
}

function closeDeleteConfirmation() {
    document.getElementById('delete-confirmation-modal').classList.remove('active');
    deleteUserId = null;
}

// User List
function renderUserList() {
    const userList = document.getElementById('user-list');
    const searchTerm = document.getElementById('user-search').value.toLowerCase();
    
    const filteredUsers = users.filter(user =>
        user.name.toLowerCase().includes(searchTerm) ||
        user.id.toString().includes(searchTerm) ||
        (user.rfidUid && user.rfidUid.toLowerCase().includes(searchTerm)) ||
        (user.fingerprintFid && user.fingerprintFid.toLowerCase().includes(searchTerm))
    );
    
    if (filteredUsers.length === 0) {
        userList.innerHTML = '<p class="empty-message">No users found</p>';
        return;
    }
    
    userList.innerHTML = filteredUsers.map(user => `
        <div class="user-item">
            <div class="user-item-header">
                <div class="user-item-info">
                    <div class="user-item-name">
                        <h4>${escapeHtml(user.name)}</h4>
                        ${user.isAdmin ? `
                            <span class="badge">
                                <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                                    <path d="M12 22s8-4 8-10V5l-8-3-8 3v7c0 6 8 10 8 10z"></path>
                                </svg>
                                Admin
                            </span>
                        ` : ''}
                    </div>
                    <p class="user-item-slot">ID Slot: ${user.id}</p>
                </div>
                <div class="user-item-actions">
                    <button class="btn btn-outline btn-icon" onclick="editUser(${JSON.stringify(user).replace(/"/g, '&quot;')})">
                        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                            <path d="M11 4H4a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h14a2 2 0 0 0 2-2v-7"></path>
                            <path d="M18.5 2.5a2.121 2.121 0 0 1 3 3L12 15l-4 1 1-4 9.5-9.5z"></path>
                        </svg>
                    </button>
                    <button class="btn btn-outline btn-icon" onclick="deleteUser(${user.id})">
                        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" style="color: #dc2626;">
                            <polyline points="3 6 5 6 21 6"></polyline>
                            <path d="M19 6v14a2 2 0 0 1-2 2H7a2 2 0 0 1-2-2V6m3 0V4a2 2 0 0 1 2-2h4a2 2 0 0 1 2 2v2"></path>
                        </svg>
                    </button>
                </div>
            </div>
            <div class="user-item-details">
                ${user.rfidUid ? `
                    <div class="user-item-detail">
                        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                            <rect x="1" y="4" width="22" height="16" rx="2" ry="2"></rect>
                            <line x1="1" y1="10" x2="23" y2="10"></line>
                        </svg>
                        <code>${user.rfidUid}</code>
                    </div>
                ` : ''}
                ${user.fingerprintFid ? `
                    <div class="user-item-detail">
                        <svg class="icon-sm" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                            <path d="M2 12C2 6.5 6.5 2 12 2a10 10 0 0 1 8 4"></path>
                            <path d="M5 19.5C5.5 18 6 15 6 12c0-.7.12-1.37.34-2"></path>
                            <path d="M17.29 21.02c.12-.6.43-2.3.5-3.02"></path>
                        </svg>
                        <code>${user.fingerprintFid}</code>
                    </div>
                ` : ''}
            </div>
        </div>
    `).join('');
}

function handleUserSearch() {
    renderUserList();
}

// ID Grid
function renderIdGrid() {
    const idGrid = document.getElementById('id-grid');
    const slots = Array.from({ length: 100 }, (_, i) => i + 1);
    
    idGrid.innerHTML = slots.map(slotId => {
        const user = users.find(u => u.id === slotId);
        const isRegistered = !!user;
        
        return `
            <button 
                class="id-slot ${isRegistered ? 'registered' : 'available'}"
                id="slot-${slotId}"
                ${isRegistered ? `onclick="selectSlot(${slotId})"` : 'disabled'}
                title="${user ? escapeHtml(user.name) : `Slot ${slotId} - Available`}"
            >
                ${slotId}
            </button>
        `;
    }).join('');
}

function openIdGrid() {
    document.getElementById('id-grid-modal').classList.add('active');
}

function closeIdGrid() {
    document.getElementById('id-grid-modal').classList.remove('active');
    clearGridSearch();
}

function selectSlot(slotId) {
    const user = users.find(u => u.id === slotId);
    if (user) {
        closeIdGrid();
        editUser(user);
    }
}

function searchInGrid() {
    const searchTerm = document.getElementById('grid-search').value.toLowerCase().trim();
    
    // Remove previous highlights
    document.querySelectorAll('.id-slot.highlighted').forEach(slot => {
        slot.classList.remove('highlighted');
    });
    
    if (!searchTerm) return;
    
    const foundUser = users.find(user => 
        user.name.toLowerCase().includes(searchTerm)
    );
    
    if (foundUser) {
        const slot = document.getElementById(`slot-${foundUser.id}`);
        if (slot) {
            slot.classList.add('highlighted');
            slot.scrollIntoView({ behavior: 'smooth', block: 'center' });
        }
    } else {
        showToast('User not found', 'error');
    }
}

function handleGridSearchInput(e) {
    const clearBtn = document.getElementById('grid-search-clear');
    clearBtn.style.display = e.target.value ? 'flex' : 'none';
}

function clearGridSearch() {
    document.getElementById('grid-search').value = '';
    document.getElementById('grid-search-clear').style.display = 'none';
    document.querySelectorAll('.id-slot.highlighted').forEach(slot => {
        slot.classList.remove('highlighted');
    });
}

// Sensor History
function openSensorHistory(type) {
    currentSensorHistoryType = type;
    
    const title = type === 'rfid' ? 'Recent RFID Scans' : 'Recent Fingerprint Scans';
    document.getElementById('sensor-history-title').textContent = title;
    
    const readings = sensorReadings
        .filter(reading => type === 'rfid' ? reading.uid : reading.fid)
        .slice(0, 3);
    
    const historyList = document.getElementById('sensor-history-list');
    
    if (readings.length === 0) {
        historyList.innerHTML = '<p class="sensor-history-empty">No recent scans available</p>';
    } else {
        historyList.innerHTML = readings.map((reading, index) => {
            const value = type === 'rfid' ? reading.uid : reading.fid;
            const timeAgo = formatTimeAgo(reading.timestamp);
            
            return `
                <button class="sensor-history-item" onclick="selectSensorReading('${value}')">
                    <div class="sensor-history-item-data">
                        <p class="sensor-history-item-value">${value}</p>
                        <p class="sensor-history-item-time">${timeAgo}</p>
                    </div>
                    <span class="sensor-history-item-index">#${index + 1}</span>
                </button>
            `;
        }).join('');
    }
    
    document.getElementById('sensor-history-modal').classList.add('active');
}

function closeSensorHistory() {
    document.getElementById('sensor-history-modal').classList.remove('active');
    currentSensorHistoryType = null;
}

function selectSensorReading(value) {
    if (currentSensorHistoryType === 'rfid') {
        document.getElementById('user-rfid').value = value;
        currentSensorData.uid = value;
    } else {
        document.getElementById('user-fingerprint').value = value;
        currentSensorData.fid = value;
    }
    closeSensorHistory();
}

// Admin Authentication
function openAdminAuth() {
    document.getElementById('admin-auth-modal').classList.add('active');
    document.getElementById('admin-password').focus();
}

function closeAdminAuth() {
    document.getElementById('admin-auth-modal').classList.remove('active');
    document.getElementById('admin-password').value = '';
    document.getElementById('admin-auth-error').style.display = 'none';
}

function handleAdminAuth(e) {
    e.preventDefault();
    
    const password = document.getElementById('admin-password').value;
    
    if (password === ADMIN_PASSWORD) {
        document.getElementById('user-admin').checked = pendingAdminState;
        closeAdminAuth();
    } else {
        document.getElementById('admin-auth-error').style.display = 'block';
        document.getElementById('admin-password').value = '';
    }
}

// Update Counts
function updateCounts() {
    const registeredCount = users.length;
    const availableCount = 100 - registeredCount;
    
    document.getElementById('user-count').textContent = registeredCount;
    document.getElementById('grid-count').textContent = registeredCount;
    document.getElementById('registered-count').textContent = registeredCount;
    document.getElementById('available-count').textContent = availableCount;
}

// Toast Notifications
function showToast(message, type = 'success') {
    const toastContainer = document.getElementById('toast-container');
    const toast = document.createElement('div');
    toast.className = `toast ${type}`;
    
    const icon = type === 'success' 
        ? '<svg class="icon toast-icon success" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><polyline points="20 6 9 17 4 12"></polyline></svg>'
        : '<svg class="icon toast-icon error" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><circle cx="12" cy="12" r="10"></circle><line x1="15" y1="9" x2="9" y2="15"></line><line x1="9" y1="9" x2="15" y2="15"></line></svg>';
    
    toast.innerHTML = `
        ${icon}
        <span class="toast-message">${escapeHtml(message)}</span>
    `;
    
    toastContainer.appendChild(toast);
    
    setTimeout(() => {
        toast.style.animation = 'slideIn 0.3s reverse';
        setTimeout(() => toast.remove(), 300);
    }, 3000);
}

// Utility Functions
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

function formatTimeAgo(timestamp) {
    const seconds = Math.floor((Date.now() - timestamp) / 1000);
    
    if (seconds < 60) return 'just now';
    if (seconds < 3600) return `${Math.floor(seconds / 60)} minutes ago`;
    if (seconds < 86400) return `${Math.floor(seconds / 3600)} hours ago`;
    return `${Math.floor(seconds / 86400)} days ago`;
}
