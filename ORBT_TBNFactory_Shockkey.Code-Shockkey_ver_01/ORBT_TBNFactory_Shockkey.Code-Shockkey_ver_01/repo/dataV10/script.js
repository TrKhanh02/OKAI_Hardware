let userIdCounter = 1;

// Thêm một số dữ liệu mẫu ban đầu
document.addEventListener('DOMContentLoaded', () => {
    const initialUsers = [
        { name: 'Quản trị viên', type: 'Vân tay', authID: 'FP_001' }
    ];
    initialUsers.forEach(user => renderUser(user.name, user.type, user.authID));
});

function addUser() {
    const nameInput = document.getElementById('userName');
    const typeInput = document.getElementById('authType');
    const authIDInput = document.getElementById('authID');

    const name = nameInput.value.trim();
    const type = typeInput.value;
    const authID = authIDInput.value.trim();

    if (!name || !authID) {
        alert("Vui lòng không để trống thông tin!");
        return;
    }

    renderUser(name, type, authID);

    // Xóa trắng form
    nameInput.value = '';
    authIDInput.value = '';
}

function renderUser(name, type, authID) {
    const tableBody = document.getElementById('userTableBody');
    const row = document.createElement('tr');

    row.innerHTML = `
        <td>${userIdCounter++}</td>
        <td><strong>${name}</strong></td>
        <td>${type}</td>
        <td><code>${authID}</code></td>
        <td><span class="status-badge">Đang hoạt động</span></td>
        <td>
            <button class="btn-delete" onclick="deleteUser(this)">Xóa</button>
        </td>
    `;

    tableBody.appendChild(row);
}

function deleteUser(button) {
    if (confirm("Bạn có chắc chắn muốn xóa người dùng này khỏi hệ thống?")) {
        const row = button.closest('tr');
        row.style.opacity = '0';
        row.style.transition = '0.3s';
        
        setTimeout(() => {
            row.remove();
        }, 300);
    }
}