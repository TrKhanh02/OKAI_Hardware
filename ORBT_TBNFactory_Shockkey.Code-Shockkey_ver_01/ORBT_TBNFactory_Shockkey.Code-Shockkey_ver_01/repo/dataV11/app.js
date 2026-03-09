// State
let users = [];
let sensorReadings = [];
let editingUserId = null;
let selectedSlotId = null;
let highlightedId = null;
let searchQuery = "";
let ws = null;

function connectWebSocket() {
  ws = new WebSocket("ws://192.168.4.1/ws"); // IP ESP32

  ws.onopen = () => {
    console.log("WebSocket connected");
  };

  ws.onmessage = (event) => {
    try {
      // console.log("RAW:", event.data);
      const data = JSON.parse(event.data);
      console.log("Parsed data:", data);
      handleSensorData(data);
    } catch (e) {
      console.error("Invalid JSON", event.data);
    }
  };

  ws.onclose = () => {
    console.warn("WebSocket disconnected, retrying...");
    setTimeout(connectWebSocket, 2000);
  };

  ws.onerror = (err) => {
    console.error("WebSocket error", err);
  };
}

function handleSensorData(data) {
  // data = { type: "rfid", value: "A1B2C3D4" }
  // console.log('Received sensor data:', data);

  if (!data.action || !data.payload) return;
  const newReading = {};
  switch (data.action) {
    case "fingerprint":
      newReading.type = data.action; // 'rfid' | 'fingerprint'
      newReading.value = data.payload.fid; // Fingerprint ID
      break;
    case "rfid":
      newReading.type = data.action; // 'rfid' | 'fingerprint'
      newReading.value = data.payload.uid; // UID
      break;
    default:
      return;
  }

  sensorReadings.unshift(newReading);
  sensorReadings = sensorReadings.slice(0, 20);

  saveSensorData();
  updateSensorDisplay();
  updateOpenPickers();
}

// Initialize app
document.addEventListener("DOMContentLoaded", function () {
  loadData();
  initEventListeners();
  connectWebSocket();
  render();
});

// Load data from localStorage
function loadData() {
  const savedUsers = localStorage.getItem("sockKeyUsers");
  if (savedUsers) {
    users = JSON.parse(savedUsers);
  }

  const savedSensorData = localStorage.getItem("sockKeySensorData");
  if (savedSensorData) {
    sensorReadings = JSON.parse(savedSensorData);
  }
}

// Save data to localStorage
function saveUsers() {
  localStorage.setItem("sockKeyUsers", JSON.stringify(users));
}

function saveSensorData() {
  localStorage.setItem("sockKeySensorData", JSON.stringify(sensorReadings));
}

// // Simulate sensor readings
// function startSensorSimulation() {
//   setInterval(() => {
//     const type = Math.random() > 0.5 ? 'rfid' : 'fingerprint';
//     const value = type === 'rfid'
//       ? `RFID-${Math.random().toString(36).substring(2, 10).toUpperCase()}`
//       : `FP-${Math.random().toString(36).substring(2, 14).toUpperCase()}`;

//     const newReading = {
//       type: type,
//       value: value,
//       timestamp: new Date().toISOString()
//     };

//     sensorReadings.unshift(newReading);
//     sensorReadings = sensorReadings.slice(0, 20); // Keep last 20 readings
//     saveSensorData();

//     updateSensorDisplay();
//     updateOpenPickers();
//   }, 5000); // New reading every 5 seconds
// }

// Initialize event listeners
function initEventListeners() {
  // Toggle ID slots modal
  document.getElementById("toggleIdSlotsBtn").addEventListener("click", () => {
    document.getElementById("idSlotsModal").style.display = "flex";
    renderIdSlots();
  });

  document.getElementById("closeIdSlotsBtn").addEventListener("click", () => {
    document.getElementById("idSlotsModal").style.display = "none";
    selectedSlotId = null;
  });

  // Search
  document.getElementById("searchInput").addEventListener("input", (e) => {
    searchQuery = e.target.value;
    handleSearch(searchQuery);
  });

  // Add user form
  document
    .getElementById("addUserForm")
    .addEventListener("submit", handleAddUser);

  // Sensor pickers for add form
  document.getElementById("rfidPickerBtn").addEventListener("click", () => {
    togglePicker("rfidPicker", "rfid");
  });

  document
    .getElementById("fingerprintPickerBtn")
    .addEventListener("click", () => {
      togglePicker("fingerprintPicker", "fingerprint");
    });

  // Edit user modal
  document
    .getElementById("closeEditBtn")
    .addEventListener("click", closeEditModal);
  document
    .getElementById("cancelEditBtn")
    .addEventListener("click", closeEditModal);
  document
    .getElementById("editUserForm")
    .addEventListener("submit", handleEditUser);

  // Sensor pickers for edit form
  document.getElementById("editRfidPickerBtn").addEventListener("click", () => {
    togglePicker("editRfidPicker", "rfid");
  });

  document
    .getElementById("editFingerprintPickerBtn")
    .addEventListener("click", () => {
      togglePicker("editFingerprintPicker", "fingerprint");
    });

  // Close modals on backdrop click
  document.getElementById("idSlotsModal").addEventListener("click", (e) => {
    if (e.target.id === "idSlotsModal") {
      document.getElementById("idSlotsModal").style.display = "none";
      selectedSlotId = null;
    }
  });

  document.getElementById("editUserModal").addEventListener("click", (e) => {
    if (e.target.id === "editUserModal") {
      closeEditModal();
    }
  });
}

// Toggle sensor picker
function togglePicker(pickerId, type) {
  const picker = document.getElementById(pickerId);
  const isVisible = picker.style.display === "block";

  // Hide all pickers
  document
    .querySelectorAll(".sensor-picker")
    .forEach((p) => (p.style.display = "none"));

  if (!isVisible) {
    picker.style.display = "block";
    renderSensorPicker(pickerId, type);
  }
}

// Render sensor picker
function renderSensorPicker(pickerId, type) {
  const picker = document.getElementById(pickerId);
  const filteredReadings = sensorReadings
    .filter((r) => r.type === type)
    .slice(0, 3);

  const iconSvg =
    type === "rfid"
      ? '<svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><rect width="20" height="14" x="2" y="5" rx="2"/><line x1="2" x2="22" y1="10" y2="10"/></svg>'
      : '<svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M2 12C2 6.5 6.5 2 12 2a10 10 0 0 1 8 4"/><path d="M5 19.5C5.5 18 6 15 6 12c0-.7.12-1.37.34-2"/><path d="M17.29 21.02c.12-.6.43-2.3.5-3.02"/><path d="M12 10a2 2 0 0 0-2 2c0 1.02-.1 2.51-.26 4"/><path d="M8.65 22c.21-.66.45-1.32.57-2"/><path d="M14 13.12c0 2.38 0 6.38-1 8.88"/><path d="M2 16h.01"/><path d="M21.8 16c.2-2 .131-5.354 0-6"/><path d="M9 6.8a6 6 0 0 1 9 5.2c0 .47 0 1.17-.02 2"/></svg>';

  let html = `
    <div class="picker-header">
      <div class="picker-title">
        ${iconSvg}
        <span>Recent ${type === "rfid" ? "RFID" : "Fingerprint"} Scans</span>
      </div>
      <button type="button" class="icon-btn" onclick="document.getElementById('${pickerId}').style.display='none'">
        <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
          <line x1="18" x2="6" y1="6" y2="18"/>
          <line x1="6" x2="18" y1="6" y2="18"/>
        </svg>
      </button>
    </div>
  `;

  if (filteredReadings.length === 0) {
    html += `<div class="picker-empty">No ${type === "rfid" ? "RFID" : "fingerprint"} scans available yet</div>`;
  } else {
    html += '<div class="picker-list">';
    filteredReadings.forEach((reading) => {
      html += `
        <button type="button" class="picker-item ${type}" onclick="selectSensorValue('${pickerId}', '${reading.value}')">
          <div class="picker-item-value">${reading.value}</div>
          <div class="picker-item-time">
            <svg xmlns="http://www.w3.org/2000/svg" width="12" height="12" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <circle cx="12" cy="12" r="10"/>
              <polyline points="12 6 12 12 16 14"/>
            </svg>
            ${formatTime(reading.timestamp)}
          </div>
        </button>
      `;
    });
    html += "</div>";
  }

  picker.innerHTML = html;
}

// Select sensor value
function selectSensorValue(pickerId, value) {
  if (pickerId === "rfidPicker") {
    document.getElementById("userRfid").value = value;
  } else if (pickerId === "fingerprintPicker") {
    document.getElementById("userFingerprint").value = value;
  } else if (pickerId === "editRfidPicker") {
    document.getElementById("editUserRfid").value = value;
  } else if (pickerId === "editFingerprintPicker") {
    document.getElementById("editUserFingerprint").value = value;
  }

  document.getElementById(pickerId).style.display = "none";
}

// Update open pickers when new sensor data arrives
function updateOpenPickers() {
  document.querySelectorAll(".sensor-picker").forEach((picker) => {
    if (picker.style.display === "block") {
      const type = picker.id.includes("rfid") ? "rfid" : "fingerprint";
      renderSensorPicker(picker.id, type);
    }
  });
}

// Handle add user
function handleAddUser(e) {
  e.preventDefault();

  const name = document.getElementById("userName").value.trim();
  const rfid = document.getElementById("userRfid").value;
  const fingerprint = document.getElementById("userFingerprint").value;

  if (!name || !rfid || !fingerprint) {
    alert("Please fill in all fields");
    return;
  }

  if (users.length >= 100) {
    alert("Maximum capacity reached (100 users)");
    return;
  }

  // Find first available ID
  const occupiedIds = users.map((u) => u.id);
  let newId = 1;
  for (let i = 1; i <= 100; i++) {
    if (!occupiedIds.includes(i)) {
      newId = i;
      break;
    }
  }

  const newUser = {
    id: newId,
    name: name,
    rfid: rfid,
    fingerprint: fingerprint,
    dateAdded: new Date().toISOString(),
  };

  users.push(newUser);
  saveUsers();

  // Reset form
  document.getElementById("addUserForm").reset();

  render();
}

// Handle edit user
function openEditModal(userId) {
  const user = users.find((u) => u.id === userId);
  if (!user) return;

  editingUserId = userId;

  document.getElementById("editUserTitle").textContent =
    `Edit User #${user.id}`;
  document.getElementById("editUserName").value = user.name;
  document.getElementById("editUserRfid").value = user.rfid;
  document.getElementById("editUserFingerprint").value = user.fingerprint;

  document.getElementById("editUserModal").style.display = "flex";
}

function closeEditModal() {
  document.getElementById("editUserModal").style.display = "none";
  editingUserId = null;
}

function handleEditUser(e) {
  e.preventDefault();

  if (!editingUserId) return;

  const name = document.getElementById("editUserName").value.trim();
  const rfid = document.getElementById("editUserRfid").value;
  const fingerprint = document.getElementById("editUserFingerprint").value;

  if (!name || !rfid || !fingerprint) {
    alert("Please fill in all fields");
    return;
  }

  const userIndex = users.findIndex((u) => u.id === editingUserId);
  if (userIndex !== -1) {
    users[userIndex] = {
      ...users[userIndex],
      name: name,
      rfid: rfid,
      fingerprint: fingerprint,
    };
    saveUsers();
  }

  closeEditModal();
  render();

  // Update ID slots view if open
  if (document.getElementById("idSlotsModal").style.display === "flex") {
    renderIdSlots();
    if (selectedSlotId === editingUserId) {
      renderUserDetails(editingUserId);
    }
  }
}

// Delete user
function deleteUser(userId) {
  const user = users.find((u) => u.id === userId);
  if (!user) return;

  if (confirm(`Are you sure you want to delete ${user.name}?`)) {
    users = users.filter((u) => u.id !== userId);
    saveUsers();
    render();

    // Update ID slots view if open
    if (document.getElementById("idSlotsModal").style.display === "flex") {
      renderIdSlots();
      if (selectedSlotId === userId) {
        selectedSlotId = null;
        document.getElementById("userDetailsPanel").innerHTML = `
          <div class="empty-state">
            <div class="empty-icon">
              <svg xmlns="http://www.w3.org/2000/svg" width="32" height="32" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <circle cx="11" cy="11" r="8"/>
                <path d="m21 21-4.3-4.3"/>
              </svg>
            </div>
            <p>Select an ID slot to view details</p>
            <p class="text-muted">Click on a red slot to view registered user</p>
          </div>
        `;
      }
    }
  }
}

// Handle search
function handleSearch(query) {
  if (query.trim()) {
    const foundUser = users.find((u) =>
      u.name.toLowerCase().includes(query.toLowerCase()),
    );
    if (foundUser) {
      highlightedId = foundUser.id;
    } else {
      highlightedId = null;
    }
  } else {
    highlightedId = null;
  }

  renderIdSlots();
}

// Render ID slots
function renderIdSlots() {
  const grid = document.getElementById("idSlotsGrid");
  let html = "";

  for (let i = 1; i <= 100; i++) {
    const user = users.find((u) => u.id === i);
    const isRegistered = !!user;
    const isHighlighted = highlightedId === i;
    const isSelected = selectedSlotId === i;

    html += `
      <button 
        class="id-slot ${isRegistered ? "registered" : "available"} ${isHighlighted ? "highlighted" : ""} ${isSelected ? "selected" : ""}"
        onclick="selectIdSlot(${i})"
        title="${user ? `ID ${i}: ${user.name}` : `ID ${i}: Available`}"
      >
        ${i}
      </button>
    `;
  }

  grid.innerHTML = html;
  document.getElementById("slotsOccupied").textContent =
    `${users.length} of 100 slots occupied`;
}

// Select ID slot
function selectIdSlot(slotId) {
  const user = users.find((u) => u.id === slotId);
  if (user) {
    selectedSlotId = slotId;
    renderIdSlots();
    renderUserDetails(slotId);
  }
}

// Render user details
function renderUserDetails(userId) {
  const user = users.find((u) => u.id === userId);
  if (!user) return;

  const panel = document.getElementById("userDetailsPanel");

  panel.innerHTML = `
    <div>
      <div class="user-details-header">
        <h3>User Details</h3>
        <div style="display: flex; gap: 0.5rem;">
          <button class="action-btn edit" onclick="openEditModal(${user.id})" title="Edit user">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <path d="M17 3a2.85 2.83 0 1 1 4 4L7.5 20.5 2 22l1.5-5.5Z"/>
              <path d="m15 5 4 4"/>
            </svg>
          </button>
          <button class="action-btn delete" onclick="deleteUser(${user.id})" title="Delete user">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <path d="M3 6h18"/>
              <path d="M19 6v14c0 1-1 2-2 2H7c-1 0-2-1-2-2V6"/>
              <path d="M8 6V4c0-1 1-2 2-2h4c1 0 2 1 2 2v2"/>
            </svg>
          </button>
        </div>
      </div>

      <div class="user-details-card">
        <div class="user-profile">
          <div class="user-profile-badge">${user.id}</div>
          <div class="user-profile-info">
            <h4>${user.name}</h4>
            <p>ID Slot #${user.id}</p>
          </div>
        </div>

        <div class="credential-box rfid">
          <div class="credential-box-header">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <rect width="20" height="14" x="2" y="5" rx="2"/>
              <line x1="2" x2="22" y1="10" y2="10"/>
            </svg>
            <span>RFID Card</span>
          </div>
          <div class="credential-box-value">${user.rfid}</div>
        </div>

        <div class="credential-box fingerprint">
          <div class="credential-box-header">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <path d="M2 12C2 6.5 6.5 2 12 2a10 10 0 0 1 8 4"/>
              <path d="M5 19.5C5.5 18 6 15 6 12c0-.7.12-1.37.34-2"/>
              <path d="M17.29 21.02c.12-.6.43-2.3.5-3.02"/>
              <path d="M12 10a2 2 0 0 0-2 2c0 1.02-.1 2.51-.26 4"/>
              <path d="M8.65 22c.21-.66.45-1.32.57-2"/>
              <path d="M14 13.12c0 2.38 0 6.38-1 8.88"/>
              <path d="M2 16h.01"/>
              <path d="M21.8 16c.2-2 .131-5.354 0-6"/>
              <path d="M9 6.8a6 6 0 0 1 9 5.2c0 .47 0 1.17-.02 2"/>
            </svg>
            <span>Fingerprint</span>
          </div>
          <div class="credential-box-value">${user.fingerprint}</div>
        </div>

        <div class="credential-box date">
          <div class="credential-box-header">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <rect width="18" height="18" x="3" y="4" rx="2" ry="2"/>
              <line x1="16" x2="16" y1="2" y2="6"/>
              <line x1="8" x2="8" y1="2" y2="6"/>
              <line x1="3" x2="21" y1="10" y2="10"/>
            </svg>
            <span>Date Added</span>
          </div>
          <div class="credential-box-value">${formatDate(user.dateAdded)}</div>
        </div>
      </div>
    </div>
  `;
}

// Update sensor display
function updateSensorDisplay() {
  const latestRfid = sensorReadings.find((r) => r.type === "rfid");
  const latestFingerprint = sensorReadings.find((r) => r.type === "fingerprint");

  const rfidElement = document.getElementById("latestRfid");
  const rfidTimeElement = document.getElementById("latestRfidTime");
  const fingerprintElement = document.getElementById("latestFingerprint");
  const fingerprintTimeElement = document.getElementById(
    "latestFingerprintTime",
  );

  console.log('Latest RFID:', latestRfid);
  console.log('Latest Fingerprint:', latestFingerprint);

  if (latestRfid) {
    rfidElement.textContent = latestRfid.value;
    rfidElement.style.fontStyle = "normal";
    rfidTimeElement.textContent = formatTime(latestRfid.timestamp);
  } else {
    rfidElement.textContent = "Waiting for scan...";
    rfidElement.style.fontStyle = "italic";
    rfidTimeElement.textContent = "";
  }

  if (latestFingerprint) {
    fingerprintElement.textContent = latestFingerprint.value;
    fingerprintElement.style.fontStyle = "normal";
    fingerprintTimeElement.textContent = formatTime(
      latestFingerprint.timestamp,
    );
  } else {
    fingerprintElement.textContent = "Waiting for scan...";
    fingerprintElement.style.fontStyle = "italic";
    fingerprintTimeElement.textContent = "";
  }
}

// Render user list
function renderUserList() {
  const userList = document.getElementById("userList");
  const userListCount = document.getElementById("userListCount");

  userListCount.textContent = `${users.length} user${users.length !== 1 ? "s" : ""}`;

  if (users.length === 0) {
    userList.innerHTML = `
      <div class="empty-state">
        <svg xmlns="http://www.w3.org/2000/svg" width="48" height="48" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
          <path d="M16 21v-2a4 4 0 0 0-4-4H6a4 4 0 0 0-4 4v2"/>
          <circle cx="9" cy="7" r="4"/>
          <path d="M22 21v-2a4 4 0 0 0-3-3.87"/>
          <path d="M16 3.13a4 4 0 0 1 0 7.75"/>
        </svg>
        <p>No users registered yet</p>
        <p class="text-muted">Add your first user to get started</p>
      </div>
    `;
    return;
  }

  let html = "";
  users.forEach((user) => {
    html += `
      <div class="user-item">
        <div class="user-item-content">
          <div class="user-item-info">
            <div class="user-item-header">
              <div class="user-id-badge">${user.id}</div>
              <h3 class="user-name">${user.name}</h3>
            </div>
            
            <div class="user-credentials">
              <div class="credential-row">
                <svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                  <rect width="20" height="14" x="2" y="5" rx="2"/>
                  <line x1="2" x2="22" y1="10" y2="10"/>
                </svg>
                <span>${user.rfid}</span>
              </div>
              <div class="credential-row">
                <svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                  <path d="M2 12C2 6.5 6.5 2 12 2a10 10 0 0 1 8 4"/>
                  <path d="M5 19.5C5.5 18 6 15 6 12c0-.7.12-1.37.34-2"/>
                  <path d="M17.29 21.02c.12-.6.43-2.3.5-3.02"/>
                  <path d="M12 10a2 2 0 0 0-2 2c0 1.02-.1 2.51-.26 4"/>
                  <path d="M8.65 22c.21-.66.45-1.32.57-2"/>
                  <path d="M14 13.12c0 2.38 0 6.38-1 8.88"/>
                  <path d="M2 16h.01"/>
                  <path d="M21.8 16c.2-2 .131-5.354 0-6"/>
                  <path d="M9 6.8a6 6 0 0 1 9 5.2c0 .47 0 1.17-.02 2"/>
                </svg>
                <span>${user.fingerprint}</span>
              </div>
            </div>
          </div>

          <div class="user-actions">
            <button class="action-btn edit" onclick="openEditModal(${user.id})" title="Edit user">
              <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <path d="M17 3a2.85 2.83 0 1 1 4 4L7.5 20.5 2 22l1.5-5.5Z"/>
                <path d="m15 5 4 4"/>
              </svg>
            </button>
            <button class="action-btn delete" onclick="deleteUser(${user.id})" title="Delete user">
              <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <path d="M3 6h18"/>
                <path d="M19 6v14c0 1-1 2-2 2H7c-1 0-2-1-2-2V6"/>
                <path d="M8 6V4c0-1 1-2 2-2h4c1 0 2 1 2 2v2"/>
              </svg>
            </button>
          </div>
        </div>
      </div>
    `;
  });

  userList.innerHTML = html;
}

// Render everything
function render() {
  document.getElementById("userCount").textContent = `${users.length}/100`;
  updateSensorDisplay();
  renderUserList();

  // Update add button state
  const addBtn = document.getElementById("addUserBtn");
  if (users.length >= 100) {
    addBtn.disabled = true;
    addBtn.textContent = "Maximum Capacity Reached";
  } else {
    addBtn.disabled = false;
    addBtn.textContent = "Add User";
  }
}

// Format time
function formatTime(timestamp) {
  const date = new Date(timestamp);
  return date.toLocaleTimeString("en-US", {
    hour: "2-digit",
    minute: "2-digit",
    second: "2-digit",
  });
}

// Format date
function formatDate(dateString) {
  const date = new Date(dateString);
  return date.toLocaleDateString("en-US", {
    month: "short",
    day: "numeric",
    year: "numeric",
    hour: "2-digit",
    minute: "2-digit",
  });
}
