import { useState, useEffect } from 'react';
import { SensorPanel, SensorReading } from './components/sensor-panel';
import { IdGrid, User } from './components/id-grid';
import { UserForm } from './components/user-form';
import { UserList } from './components/user-list';
import { ConfirmationDialog } from './components/confirmation-dialog';
import { Toaster, toast } from 'sonner';
import { Lock } from 'lucide-react';

const ADMIN_PASSWORD = 'admin123';

export default function App() {
  const [users, setUsers] = useState<User[]>([]);
  const [sensorReadings, setSensorReadings] = useState<SensorReading[]>([]);
  const [currentSensorData, setCurrentSensorData] = useState<{ uid?: string; fid?: string }>({});
  const [editingUser, setEditingUser] = useState<User | null>(null);
  const [currentIdSlot, setCurrentIdSlot] = useState<number>(1);
  const [deleteConfirmation, setDeleteConfirmation] = useState<{
    open: boolean;
    userId: number | null;
    userName: string;
  }>({ open: false, userId: null, userName: '' });

  // Load users from localStorage
  useEffect(() => {
    const savedUsers = localStorage.getItem('smartlock-users');
    if (savedUsers) {
      setUsers(JSON.parse(savedUsers));
    }

    // Load sensor readings
    const savedReadings = localStorage.getItem('smartlock-readings');
    if (savedReadings) {
      setSensorReadings(JSON.parse(savedReadings));
    }
  }, []);

  // Save users to localStorage
  useEffect(() => {
    localStorage.setItem('smartlock-users', JSON.stringify(users));
  }, [users]);

  // Save sensor readings to localStorage
  useEffect(() => {
    localStorage.setItem('smartlock-readings', JSON.stringify(sensorReadings));
  }, [sensorReadings]);

  const handleSensorData = (data: { uid?: string; fid?: string }) => {
    // Add to sensor readings history
    const newReading: SensorReading = {
      uid: data.uid,
      fid: data.fid,
      timestamp: Date.now(),
    };
    
    setSensorReadings(prev => [newReading, ...prev].slice(0, 20)); // Keep last 20 readings
    
    // Update current sensor data - this will overwrite previous values
    setCurrentSensorData(prev => ({
      uid: data.uid || prev.uid,
      fid: data.fid || prev.fid,
    }));

    if (data.uid) {
      toast.success('RFID UID saved successfully');
    }
    if (data.fid) {
      toast.success('Fingerprint FID saved successfully');
    }
  };

  const handleAddUser = (userData: Partial<User>) => {
    if (!userData.id || !userData.name) {
      toast.error('Please fill in all required fields');
      return;
    }

    // Check if ID slot is already taken
    const existingUser = users.find(u => u.id === userData.id);
    if (existingUser) {
      toast.error(`ID slot ${userData.id} is already taken by ${existingUser.name}`);
      return;
    }

    // Validate FID matches ID slot
    if (userData.fingerprintFid && currentSensorData.fid) {
      const fidNumber = parseInt(userData.fingerprintFid.substring(0, 2), 16);
      if (fidNumber !== userData.id) {
        toast.error(`FID must match ID slot ${userData.id}`);
        return;
      }
    }

    const newUser: User = {
      id: userData.id,
      name: userData.name,
      rfidUid: userData.rfidUid,
      fingerprintFid: userData.fingerprintFid,
      isAdmin: userData.isAdmin || false,
    };

    setUsers(prev => [...prev, newUser]);
    toast.success(`User "${newUser.name}" added successfully`);
    
    // Clear current sensor data after saving
    setCurrentSensorData({});
  };

  const handleEditUser = (userData: Partial<User>) => {
    if (!userData.id || !userData.name) {
      toast.error('Please fill in all required fields');
      return;
    }

    setUsers(prev =>
      prev.map(u =>
        u.id === userData.id
          ? {
              ...u,
              name: userData.name!,
              rfidUid: userData.rfidUid,
              fingerprintFid: userData.fingerprintFid,
              isAdmin: userData.isAdmin || false,
            }
          : u
      )
    );

    toast.success(`User "${userData.name}" updated successfully`);
    setEditingUser(null);
    
    // Clear current sensor data after saving
    setCurrentSensorData({});
  };

  const handleDeleteUser = (userId: number) => {
    const user = users.find(u => u.id === userId);
    if (!user) return;

    setDeleteConfirmation({
      open: true,
      userId,
      userName: user.name,
    });
  };

  const confirmDelete = () => {
    if (deleteConfirmation.userId === null) return;

    setUsers(prev => prev.filter(u => u.id !== deleteConfirmation.userId));
    toast.success(`User "${deleteConfirmation.userName}" deleted successfully`);
    
    if (editingUser?.id === deleteConfirmation.userId) {
      setEditingUser(null);
    }

    setDeleteConfirmation({ open: false, userId: null, userName: '' });
  };

  const handleSelectUserFromGrid = (userId: number) => {
    const user = users.find(u => u.id === userId);
    if (user) {
      setEditingUser(user);
      // Scroll to edit form on mobile
      setTimeout(() => {
        document.getElementById('user-form-section')?.scrollIntoView({ 
          behavior: 'smooth', 
          block: 'start' 
        });
      }, 100);
    }
  };

  return (
    <div className="min-h-screen bg-gray-50">
      <Toaster position="top-right" />
      
      {/* Header */}
      <div className="bg-white border-b sticky top-0 z-10">
        <div className="container mx-auto px-4 py-4">
          <div className="flex items-center gap-3">
            <div className="bg-blue-600 p-2 rounded-lg">
              <Lock className="h-6 w-6 text-white" />
            </div>
            <div>
              <h1 className="text-2xl font-bold">Smart Lock Manager</h1>
              <p className="text-sm text-gray-500">RFID & Fingerprint Authentication System</p>
            </div>
          </div>
        </div>
      </div>

      <div className="container mx-auto px-4 py-6">
        <div className="grid lg:grid-cols-2 gap-6">
          {/* Left Column - Sensor & User Management */}
          <div className="space-y-6">
            {/* Sensor Panel - Always visible */}
            <div className="lg:sticky lg:top-24">
              <SensorPanel
                onSensorData={handleSensorData}
                sensorReadings={sensorReadings}
                compact={false}
                targetIdSlot={editingUser?.id || currentIdSlot}
              />
            </div>

            {/* User Form */}
            <div id="user-form-section">
              <UserForm
                user={editingUser}
                onSave={editingUser ? handleEditUser : handleAddUser}
                onCancel={editingUser ? () => setEditingUser(null) : undefined}
                sensorData={currentSensorData}
                sensorReadings={sensorReadings}
                mode={editingUser ? 'edit' : 'add'}
                adminPassword={ADMIN_PASSWORD}
                onIdSlotChange={setCurrentIdSlot}
              />
            </div>
          </div>

          {/* Right Column - User List & ID Grid */}
          <div className="space-y-6">
            {/* ID Grid Button */}
            <div className="flex justify-center lg:justify-start">
              <IdGrid
                users={users}
                onSelectUser={handleSelectUserFromGrid}
                maxSlots={100}
              />
            </div>

            {/* User List */}
            <UserList
              users={users}
              onEdit={setEditingUser}
              onDelete={handleDeleteUser}
            />
          </div>
        </div>
      </div>

      {/* Delete Confirmation Dialog */}
      <ConfirmationDialog
        open={deleteConfirmation.open}
        onOpenChange={(open) =>
          setDeleteConfirmation(prev => ({ ...prev, open }))
        }
        onConfirm={confirmDelete}
        title="Delete User"
        description={`Are you sure you want to delete "${deleteConfirmation.userName}"? This action cannot be undone.`}
        confirmText="Delete"
        cancelText="Cancel"
      />
    </div>
  );
}