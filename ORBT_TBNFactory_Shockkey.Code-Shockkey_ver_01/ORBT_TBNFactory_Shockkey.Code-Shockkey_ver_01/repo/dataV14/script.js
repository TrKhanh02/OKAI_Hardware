// Application State
const state = {
  users: [],
  selectedID: null,
  isEditMode: false,
  isAdminAuthenticated: false,
  pendingEditUser: null,
  pendingDeleteUser: null,
  currentRFID: "",
  currentFingerprint: "",
  rfidHistory: [],
  fingerprintHistory: [],
  rfidScanning: false,
  rfidSaved: false,
  fpEnrolling: false,
  fpScanCount: 0,
  fpSaved: false,
  highlightedID: null,
};

const ADMIN_PASSWORD = "admin123";

// Load data from localStorage
function loadData() {
  const savedUsers = localStorage.getItem("smartLockUsers");
  if (savedUsers) {
    state.users = JSON.parse(savedUsers);
  }

  const savedRFIDHistory = localStorage.getItem("rfidHistory");
  if (savedRFIDHistory) {
    state.rfidHistory = JSON.parse(savedRFIDHistory);
  }

  const savedFPHistory = localStorage.getItem("fingerprintHistory");
  if (savedFPHistory) {
    state.fingerprintHistory = JSON.parse(savedFPHistory);
  }
}

// Save users to localStorage
function saveUsers() {
  localStorage.setItem("smartLockUsers", JSON.stringify(state.users));
}

// Generate random RFID UID
function generateRFIDUID() {
  const bytes = Array.from({ length: 4 }, () =>
    Math.floor(Math.random() * 256)
      .toString(16)
      .padStart(2, "0")
      .toUpperCase(),
  );
  return bytes.join(":");
}

// Generate random Fingerprint ID
function generateFingerprintID() {
  const bytes = Array.from({ length: 8 }, () =>
    Math.floor(Math.random() * 256)
      .toString(16)
      .padStart(2, "0")
      .toUpperCase(),
  );
  return bytes.join("");
}

// RFID Scanner Functions
function handleRFIDScan() {
  if (state.rfidScanning) return;

  state.rfidScanning = true;
  state.rfidSaved = false;
  updateRFIDDisplay();

  setTimeout(() => {
    state.currentRFID = generateRFIDUID();
    state.rfidScanning = false;
    updateRFIDDisplay();
  }, 1500);
}

function handleRFIDRefresh() {
  state.currentRFID = "";
  state.rfidSaved = false;
  handleRFIDScan();
}

function handleRFIDSave() {
  if (!state.currentRFID) return;

  const reading = {
    data: state.currentRFID,
    timestamp: Date.now(),
  };
  state.rfidHistory = [reading, ...state.rfidHistory].slice(0, 10);
  localStorage.setItem("rfidHistory", JSON.stringify(state.rfidHistory));
  state.rfidSaved = true;

  // Auto-fill form if not in edit mode
  if (!state.isEditMode && state.selectedID) {
    document.getElementById("userRfid").value = state.currentRFID;
  }

  updateRFIDDisplay();
}

function updateRFIDDisplay() {
  const display = document.getElementById("rfidDisplay");
  const scanBtn = document.getElementById("scanRfidBtn");
  const refreshBtn = document.getElementById("refreshRfidBtn");
  const saveBtn = document.getElementById("saveRfidBtn");
  const savedMsg = document.getElementById("rfidSaved");

  if (state.rfidScanning) {
    display.innerHTML =
      '<span class="text-blue animate-pulse">Scanning...</span>';
    scanBtn.disabled = true;
    refreshBtn.classList.add("hidden");
    saveBtn.classList.add("hidden");
    savedMsg.classList.add("hidden");
  } else if (state.currentRFID) {
    const colorClass = state.rfidSaved ? "text-green" : "";
    display.innerHTML = `<span class="${colorClass}">${state.currentRFID}</span>`;
    scanBtn.disabled = false;

    if (state.rfidSaved) {
      refreshBtn.classList.add("hidden");
      saveBtn.classList.add("hidden");
      savedMsg.classList.remove("hidden");
    } else {
      refreshBtn.classList.remove("hidden");
      saveBtn.classList.remove("hidden");
      savedMsg.classList.add("hidden");
    }
  } else {
    display.innerHTML = '<span class="text-gray">No data</span>';
    scanBtn.disabled = false;
    refreshBtn.classList.add("hidden");
    saveBtn.classList.add("hidden");
    savedMsg.classList.add("hidden");
  }
}

// Fingerprint Scanner Functions
let fpInterval = null;

function handleFPEnroll() {
  if (state.fpEnrolling) return;

  state.fpEnrolling = true;
  state.fpScanCount = 0;
  state.currentFingerprint = "";
  state.fpSaved = false;
  updateFPDisplay();

  fpInterval = setInterval(() => {
    state.fpScanCount++;
    updateFPDisplay();

    if (state.fpScanCount >= 4) {
      clearInterval(fpInterval);
      state.fpEnrolling = false;
      state.currentFingerprint = generateFingerprintID();
      updateFPDisplay();
    }
  }, 1000);
}

function handleFPRefresh() {
  if (fpInterval) {
    clearInterval(fpInterval);
  }
  state.fpScanCount = 0;
  state.currentFingerprint = "";
  state.fpSaved = false;
  handleFPEnroll();
}

function handleFPSave() {
  if (!state.currentFingerprint) return;

  const reading = {
    data: state.currentFingerprint,
    timestamp: Date.now(),
  };
  state.fingerprintHistory = [reading, ...state.fingerprintHistory].slice(
    0,
    10,
  );
  localStorage.setItem(
    "fingerprintHistory",
    JSON.stringify(state.fingerprintHistory),
  );
  state.fpSaved = true;

  // Auto-fill form if not in edit mode
  if (!state.isEditMode && state.selectedID) {
    document.getElementById("userFp").value = state.currentFingerprint;
  }

  updateFPDisplay();
}

function updateFPDisplay() {
  const display = document.getElementById("fpDisplay");
  const enrollBtn = document.getElementById("enrollFpBtn");
  const refreshBtn = document.getElementById("refreshFpBtn");
  const saveBtn = document.getElementById("saveFpBtn");
  const savedMsg = document.getElementById("fpSaved");

  if (state.fpEnrolling) {
    display.innerHTML = `<span class="text-purple animate-pulse">Scan ${state.fpScanCount}/4...</span>`;
    enrollBtn.disabled = true;
    enrollBtn.querySelector("span").textContent = `Scan ${state.fpScanCount}/4`;
    refreshBtn.classList.add("hidden");
    saveBtn.classList.add("hidden");
    savedMsg.classList.add("hidden");
  } else if (state.currentFingerprint) {
    const colorClass = state.fpSaved ? "text-green" : "";
    display.innerHTML = `<span class="${colorClass}">${state.currentFingerprint}</span>`;
    enrollBtn.disabled = false;
    enrollBtn.querySelector("span").textContent = "Enroll";

    if (state.fpSaved) {
      refreshBtn.classList.add("hidden");
      saveBtn.classList.add("hidden");
      savedMsg.classList.remove("hidden");
    } else {
      refreshBtn.classList.remove("hidden");
      saveBtn.classList.remove("hidden");
      savedMsg.classList.add("hidden");
    }
  } else {
    display.innerHTML = '<span class="text-gray">No data</span>';
    enrollBtn.disabled = false;
    enrollBtn.querySelector("span").textContent = "Enroll";
    refreshBtn.classList.add("hidden");
    saveBtn.classList.add("hidden");
    savedMsg.classList.add("hidden");
  }
}

// Form Functions
function showUserForm(id, isEdit = false) {
  state.selectedID = id;
  state.isEditMode = isEdit;

  const form = document.getElementById("userForm");
  const formTitle = document.getElementById("formTitle");
  const cancelFormBtn = document.getElementById("cancelFormBtn");
  const submitBtn = document.getElementById("submitBtn");
  const rfidHistoryBtn = document.getElementById("rfidHistoryBtn");
  const fpHistoryBtn = document.getElementById("fpHistoryBtn");

  form.classList.remove("hidden");
  cancelFormBtn.classList.remove("hidden");
  formTitle.textContent = isEdit
    ? `Edit User - ID ${id}`
    : `Add New User - ID ${id}`;
  submitBtn.querySelector("span").textContent = isEdit
    ? "Update User"
    : "Save User";

  if (isEdit) {
    rfidHistoryBtn.classList.remove("hidden");
    fpHistoryBtn.classList.remove("hidden");
    const user = state.users.find((u) => u.id === id);
    if (user) {
      document.getElementById("userName").value = user.name;
      document.getElementById("userRfid").value = user.rfidUID;
      document.getElementById("userFp").value = user.fingerprintID;
      document.getElementById("isAdmin").checked = user.isAdmin;
      if (user.isAdmin) {
        document
          .getElementById("adminPasswordGroup")
          .classList.remove("hidden");
      }
    }
    // Clear current sensor data when editing
    state.currentRFID = "";
    state.currentFingerprint = "";
    state.rfidSaved = false;
    state.fpSaved = false;
    updateRFIDDisplay();
    updateFPDisplay();
  } else {
    rfidHistoryBtn.classList.add("hidden");
    fpHistoryBtn.classList.add("hidden");
    document.getElementById("userName").value = "";
    document.getElementById("userRfid").value = state.currentRFID;
    document.getElementById("userFp").value = state.currentFingerprint;
    document.getElementById("isAdmin").checked = false;
    document.getElementById("adminPassword").value = "";
    document.getElementById("adminPasswordGroup").classList.add("hidden");
  }
}

function hideUserForm() {
  state.selectedID = null;
  state.isEditMode = false;
  document.getElementById("userForm").classList.add("hidden");
  document.getElementById("cancelFormBtn").classList.add("hidden");
  document.getElementById("formTitle").textContent =
    "Select an ID slot to add or edit a user";
}

function handleUserFormSubmit(e) {
  e.preventDefault();

  const name = document.getElementById("userName").value.trim();
  const rfidUID = document.getElementById("userRfid").value;
  const fingerprintID = document.getElementById("userFp").value;
  const isAdmin = document.getElementById("isAdmin").checked;
  const adminPassword = document.getElementById("adminPassword").value;

  if (!state.selectedID || !name || !rfidUID || !fingerprintID) {
    alert("Please fill all required fields");
    return;
  }

  if (isAdmin && adminPassword !== ADMIN_PASSWORD) {
    alert("Incorrect administrator password");
    return;
  }

  // Validate FID matches ID (simple check - first 2 chars should match ID)
  const expectedFID = state.selectedID.toString().padStart(2, "0");
  if (!fingerprintID.startsWith(expectedFID)) {
    alert(
      `Fingerprint ID must match the registered ID slot (${state.selectedID})`,
    );
    return;
  }

  const user = {
    id: state.selectedID,
    name,
    rfidUID,
    fingerprintID,
    isAdmin,
  };

  if (state.isEditMode) {
    state.users = state.users.map((u) => (u.id === user.id ? user : u));
  } else {
    if (state.users.some((u) => u.id === user.id)) {
      alert("This ID slot is already registered");
      return;
    }
    state.users.push(user);
  }

  saveUsers();

  // Clear sensor data after saving
  state.currentRFID = "";
  state.currentFingerprint = "";
  state.rfidSaved = false;
  state.fpSaved = false;
  updateRFIDDisplay();
  updateFPDisplay();

  hideUserForm();
  renderUserList();
  updateUserCount();
}

// User List Functions
function renderUserList(searchTerm = "") {
  const userList = document.getElementById("userList");
  let filteredUsers = state.users;

  if (searchTerm) {
    filteredUsers = state.users.filter(
      (user) =>
        user.name.toLowerCase().includes(searchTerm.toLowerCase()) ||
        user.id.toString().includes(searchTerm),
    );
  }

  if (filteredUsers.length === 0) {
    userList.innerHTML =
      '<div class="empty-state">' +
      (searchTerm ? "No users found" : "No registered users yet") +
      "</div>";
    return;
  }

  userList.innerHTML = filteredUsers
    .map(
      (user) => `
                <div class="user-item">
                    <div class="flex items-center gap-4">
                        <div class="user-info">
                            <div class="user-name">
                                <span class="user-id">ID ${user.id}</span>
                                <span style="font-weight: 600;">${user.name}</span>
                                ${
                                  user.isAdmin
                                    ? `
                                <svg class="icon" style="color: #f59e0b;" fill="none" stroke="currentColor" viewBox="0 0 24 24" title="Administrator">
                                    <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 12l2 2 4-4m5.618-4.016A11.955 11.955 0 0112 2.944a11.955 11.955 0 01-8.618 3.04A12.02 12.02 0 003 9c0 5.591 3.824 10.29 9 11.622 5.176-1.332 9-6.03 9-11.622 0-1.042-.133-2.052-.382-3.016z"/>
                                </svg>
                                `
                                    : ""
                                }
                            </div>
                            <div class="user-details">
                                <div>RFID: ${user.rfidUID}</div>
                                <div>FP: ${user.fingerprintID}</div>
                            </div>
                        </div>
                        <div class="flex gap-2">
                            <button class="btn btn-icon" onclick="handleEditUser(${user.id})" title="Edit">
                                <svg class="icon text-blue" fill="none" stroke="currentColor" viewBox="0 0 24 24">
                                    <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M11 5H6a2 2 0 00-2 2v11a2 2 0 002 2h11a2 2 0 002-2v-5m-1.414-9.414a2 2 0 112.828 2.828L11.828 15H9v-2.828l8.586-8.586z"/>
                                </svg>
                            </button>
                            <button class="btn btn-icon" onclick="handleDeleteUser(${user.id})" title="Delete">
                                <svg class="icon text-red" fill="none" stroke="currentColor" viewBox="0 0 24 24">
                                    <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 7l-.867 12.142A2 2 0 0116.138 21H7.862a2 2 0 01-1.995-1.858L5 7m5 4v6m4-6v6m1-10V4a1 1 0 00-1-1h-4a1 1 0 00-1 1v3M4 7h16"/>
                                </svg>
                            </button>
                        </div>
                    </div>
                </div>
            `,
    )
    .join("");
}

function updateUserCount() {
  document.getElementById("userCount").textContent = state.users.length;
  document.getElementById("registeredCount").textContent = state.users.length;
}

// ID Grid Functions
function renderIDGrid() {
  const container = document.getElementById("idGridContainer");
  const grid = document.createElement("div");
  grid.className = "id-grid";

  for (let i = 1; i <= 100; i++) {
    const button = document.createElement("button");
    button.className = "id-slot";
    button.textContent = i;

    const isRegistered = state.users.some((u) => u.id === i);
    button.classList.add(isRegistered ? "registered" : "available");

    if (state.highlightedID === i) {
      button.classList.add("highlighted");
    }

    button.onclick = () => handleSelectIDFromGrid(i);
    grid.appendChild(button);
  }

  container.innerHTML = "";
  container.appendChild(grid);
}

function handleSelectIDFromGrid(id) {
  const existingUser = state.users.find((u) => u.id === id);

  if (existingUser) {
    if (!state.isAdminAuthenticated) {
      state.pendingEditUser = existingUser;
      showPasswordModal();
    } else {
      showUserForm(id, true);
    }
  } else {
    showUserForm(id, false);
  }

  closeGridModal();
}

function handleGridSearch() {
  const searchTerm = document.getElementById("gridSearch").value.trim();

  if (!searchTerm) {
    state.highlightedID = null;
    renderIDGrid();
    return;
  }

  const foundUser = state.users.find((user) =>
    user.name.toLowerCase().includes(searchTerm.toLowerCase()),
  );

  if (foundUser) {
    state.highlightedID = foundUser.id;
    renderIDGrid();

    // Scroll to highlighted element
    setTimeout(() => {
      const highlighted = document.querySelector(".id-slot.highlighted");
      if (highlighted) {
        highlighted.scrollIntoView({ behavior: "smooth", block: "center" });
      }
    }, 100);
  } else {
    state.highlightedID = null;
    renderIDGrid();
  }
}

// Modal Functions
function showGridModal() {
  state.highlightedID = null;
  document.getElementById("gridSearch").value = "";
  renderIDGrid();
  document.getElementById("gridModal").classList.add("active");
}

function closeGridModal() {
  document.getElementById("gridModal").classList.remove("active");
}

function showPasswordModal() {
  document.getElementById("passwordInput").value = "";
  document.getElementById("passwordError").classList.add("hidden");
  document.getElementById("passwordModal").classList.add("active");
}

function closePasswordModal() {
  state.pendingEditUser = null;
  document.getElementById("passwordModal").classList.remove("active");
}

function handlePasswordConfirm() {
  const password = document.getElementById("passwordInput").value;

  if (password === ADMIN_PASSWORD) {
    state.isAdminAuthenticated = true;
    closePasswordModal();

    if (state.pendingEditUser) {
      showUserForm(state.pendingEditUser.id, true);
      state.pendingEditUser = null;
    }
  } else {
    document.getElementById("passwordError").classList.remove("hidden");
  }
}

function showConfirmModal(user) {
  state.pendingDeleteUser = user;
  document.getElementById("confirmMessage").textContent =
    `Are you sure you want to delete ${user.name} (ID ${user.id})? This action cannot be undone.`;
  document.getElementById("confirmModal").classList.add("active");
}

function closeConfirmModal() {
  state.pendingDeleteUser = null;
  document.getElementById("confirmModal").classList.remove("active");
}

function handleConfirmDelete() {
  if (state.pendingDeleteUser) {
    state.users = state.users.filter(
      (u) => u.id !== state.pendingDeleteUser.id,
    );
    saveUsers();

    if (state.selectedID === state.pendingDeleteUser.id) {
      hideUserForm();
    }

    renderUserList();
    updateUserCount();
  }
  closeConfirmModal();
}

function showHistoryModal(type) {
  const modal = document.getElementById("historyModal");
  const title = document.getElementById("historyTitle");
  const list = document.getElementById("historyList");

  const history =
    type === "rfid" ? state.rfidHistory : state.fingerprintHistory;
  const recentHistory = history.slice(0, 3);

  title.textContent = `Recent ${type === "rfid" ? "RFID" : "Fingerprint"} Scans`;

  if (recentHistory.length === 0) {
    list.innerHTML = '<div class="empty-state">No recent scans available</div>';
  } else {
    list.innerHTML = recentHistory
      .map(
        (reading) => `
                    <div class="history-item" onclick="selectHistoryItem('${type}', '${reading.data}')">
                        <div class="history-data">${reading.data}</div>
                        <div class="history-time">
                            <svg class="icon" style="width: 12px; height: 12px; display: inline; vertical-align: middle;" fill="none" stroke="currentColor" viewBox="0 0 24 24">
                                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 8v4l3 3m6-3a9 9 0 11-18 0 9 9 0 0118 0z"/>
                            </svg>
                            ${new Date(reading.timestamp).toLocaleTimeString()}
                        </div>
                    </div>
                `,
      )
      .join("");
  }

  modal.classList.add("active");
}

function closeHistoryModal() {
  document.getElementById("historyModal").classList.remove("active");
}

function selectHistoryItem(type, data) {
  if (type === "rfid") {
    document.getElementById("userRfid").value = data;
  } else {
    document.getElementById("userFp").value = data;
  }
  closeHistoryModal();
}

// Event Handlers
function handleEditUser(id) {
  const user = state.users.find((u) => u.id === id);
  if (!user) return;

  if (!state.isAdminAuthenticated) {
    state.pendingEditUser = user;
    showPasswordModal();
  } else {
    showUserForm(id, true);
  }
}

function handleDeleteUser(id) {
  const user = state.users.find((u) => u.id === id);
  if (user) {
    showConfirmModal(user);
  }
}

// Event Listeners
document
  .getElementById("scanRfidBtn")
  .addEventListener("click", handleRFIDScan);
document
  .getElementById("refreshRfidBtn")
  .addEventListener("click", handleRFIDRefresh);
document
  .getElementById("saveRfidBtn")
  .addEventListener("click", handleRFIDSave);

document
  .getElementById("enrollFpBtn")
  .addEventListener("click", handleFPEnroll);
document
  .getElementById("refreshFpBtn")
  .addEventListener("click", handleFPRefresh);
document.getElementById("saveFpBtn").addEventListener("click", handleFPSave);

document.getElementById("openGridBtn").addEventListener("click", showGridModal);
document
  .getElementById("closeGridBtn")
  .addEventListener("click", closeGridModal);
document
  .getElementById("gridSearchBtn")
  .addEventListener("click", handleGridSearch);
document.getElementById("gridSearch").addEventListener("keypress", (e) => {
  if (e.key === "Enter") handleGridSearch();
});

document
  .getElementById("userForm")
  .addEventListener("submit", handleUserFormSubmit);
document.getElementById("cancelBtn").addEventListener("click", hideUserForm);
document
  .getElementById("cancelFormBtn")
  .addEventListener("click", hideUserForm);

document.getElementById("isAdmin").addEventListener("change", (e) => {
  const group = document.getElementById("adminPasswordGroup");
  if (e.target.checked) {
    group.classList.remove("hidden");
  } else {
    group.classList.add("hidden");
    document.getElementById("adminPassword").value = "";
  }
});

document.getElementById("userSearch").addEventListener("input", (e) => {
  renderUserList(e.target.value);
});

document
  .getElementById("rfidHistoryBtn")
  .addEventListener("click", () => showHistoryModal("rfid"));
document
  .getElementById("fpHistoryBtn")
  .addEventListener("click", () => showHistoryModal("fp"));
document
  .getElementById("closeHistoryBtn")
  .addEventListener("click", closeHistoryModal);

document
  .getElementById("closePasswordBtn")
  .addEventListener("click", closePasswordModal);
document
  .getElementById("cancelPasswordBtn")
  .addEventListener("click", closePasswordModal);
document
  .getElementById("confirmPasswordBtn")
  .addEventListener("click", handlePasswordConfirm);
document.getElementById("passwordInput").addEventListener("keypress", (e) => {
  if (e.key === "Enter") handlePasswordConfirm();
});

document
  .getElementById("closeConfirmBtn")
  .addEventListener("click", closeConfirmModal);
document
  .getElementById("cancelDeleteBtn")
  .addEventListener("click", closeConfirmModal);
document
  .getElementById("confirmDeleteBtn")
  .addEventListener("click", handleConfirmDelete);

// Close modals on overlay click
document.querySelectorAll(".modal-overlay").forEach((overlay) => {
  overlay.addEventListener("click", (e) => {
    if (e.target === overlay) {
      overlay.classList.remove("active");
    }
  });
});

// Initialize
loadData();
renderUserList();
updateUserCount();
updateRFIDDisplay();
updateFPDisplay();
