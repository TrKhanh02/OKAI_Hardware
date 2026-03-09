import { useState, useEffect } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/app/components/ui/card';
import { Input } from '@/app/components/ui/input';
import { Label } from '@/app/components/ui/label';
import { Button } from '@/app/components/ui/button';
import { Switch } from '@/app/components/ui/switch';
import { User } from './id-grid';
import { SensorReading } from './sensor-panel';
import { SensorHistoryDialog } from './sensor-history-dialog';
import { AdminAuthDialog } from './admin-auth-dialog';
import { History, UserPlus, Save, X } from 'lucide-react';

interface UserFormProps {
  user?: User | null;
  onSave: (user: Partial<User>) => void;
  onCancel?: () => void;
  sensorData: { uid?: string; fid?: string };
  sensorReadings: SensorReading[];
  mode: 'add' | 'edit';
  adminPassword: string;
  onIdSlotChange?: (idSlot: number) => void;
}

export function UserForm({
  user,
  onSave,
  onCancel,
  sensorData,
  sensorReadings,
  mode,
  adminPassword,
  onIdSlotChange,
}: UserFormProps) {
  const [name, setName] = useState('');
  const [idSlot, setIdSlot] = useState('');
  const [rfidUid, setRfidUid] = useState('');
  const [fingerprintFid, setFingerprintFid] = useState('');
  const [isAdmin, setIsAdmin] = useState(false);
  const [showRfidHistory, setShowRfidHistory] = useState(false);
  const [showFingerprintHistory, setShowFingerprintHistory] = useState(false);
  const [showAdminAuth, setShowAdminAuth] = useState(false);
  const [pendingAdminState, setPendingAdminState] = useState(false);

  useEffect(() => {
    if (user) {
      setName(user.name);
      setIdSlot(user.id.toString());
      setRfidUid(user.rfidUid || '');
      setFingerprintFid(user.fingerprintFid || '');
      setIsAdmin(user.isAdmin || false);
    } else {
      setName('');
      setIdSlot('');
      setRfidUid('');
      setFingerprintFid('');
      setIsAdmin(false);
    }
  }, [user]);

  // Auto-fill sensor data when received
  useEffect(() => {
    if (sensorData.uid) {
      setRfidUid(sensorData.uid);
    }
    if (sensorData.fid) {
      setFingerprintFid(sensorData.fid);
    }
  }, [sensorData]);

  const handleAdminToggle = (checked: boolean) => {
    setPendingAdminState(checked);
    setShowAdminAuth(true);
  };

  const handleAdminAuth = (password: string): boolean => {
    if (password === adminPassword) {
      setIsAdmin(pendingAdminState);
      return true;
    }
    return false;
  };

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    
    const userData: Partial<User> = {
      name,
      rfidUid,
      fingerprintFid,
      isAdmin,
    };

    if (mode === 'add') {
      userData.id = parseInt(idSlot);
    } else if (user) {
      userData.id = user.id;
    }

    onSave(userData);
  };

  const handleRfidHistorySelect = (uid: string) => {
    setRfidUid(uid);
  };

  const handleFingerprintHistorySelect = (fid: string) => {
    setFingerprintFid(fid);
  };

  return (
    <>
      <Card>
        <CardHeader>
          <CardTitle className="flex items-center gap-2">
            {mode === 'add' ? (
              <>
                <UserPlus className="h-5 w-5" />
                Add New User
              </>
            ) : (
              <>
                <Save className="h-5 w-5" />
                Edit User
              </>
            )}
          </CardTitle>
        </CardHeader>
        <CardContent>
          <form onSubmit={handleSubmit} className="space-y-4">
            <div className="space-y-2">
              <Label htmlFor="name">Name</Label>
              <Input
                id="name"
                value={name}
                onChange={(e) => setName(e.target.value)}
                placeholder="Enter user name"
                required
              />
            </div>

            <div className="space-y-2">
              <Label htmlFor="id-slot">ID Slot (1-100)</Label>
              <Input
                id="id-slot"
                type="number"
                min="1"
                max="100"
                value={idSlot}
                onChange={(e) => {
                  setIdSlot(e.target.value);
                  if (onIdSlotChange) {
                    onIdSlotChange(parseInt(e.target.value));
                  }
                }}
                placeholder="Enter ID slot number"
                required
                disabled={mode === 'edit'}
              />
            </div>

            <div className="space-y-2">
              <Label htmlFor="rfid">RFID UID</Label>
              <div className="flex gap-2">
                <Input
                  id="rfid"
                  value={rfidUid}
                  placeholder="Scan RFID card..."
                  readOnly
                  className="flex-1"
                />
                <Button
                  type="button"
                  variant="outline"
                  onClick={() => setShowRfidHistory(true)}
                  title="Select from recent scans"
                >
                  <History className="h-4 w-4" />
                </Button>
              </div>
            </div>

            <div className="space-y-2">
              <Label htmlFor="fingerprint">Fingerprint FID</Label>
              <div className="flex gap-2">
                <Input
                  id="fingerprint"
                  value={fingerprintFid}
                  placeholder="Enroll fingerprint..."
                  readOnly
                  className="flex-1"
                />
                <Button
                  type="button"
                  variant="outline"
                  onClick={() => setShowFingerprintHistory(true)}
                  title="Select from recent scans"
                >
                  <History className="h-4 w-4" />
                </Button>
              </div>
            </div>

            <div className="flex items-center justify-between p-3 border rounded-lg">
              <div>
                <Label htmlFor="admin">Administrator</Label>
                <p className="text-sm text-gray-500">Grant admin privileges</p>
              </div>
              <Switch
                id="admin"
                checked={isAdmin}
                onCheckedChange={handleAdminToggle}
              />
            </div>

            <div className="flex gap-2">
              <Button type="submit" className="flex-1">
                <Save className="h-4 w-4 mr-2" />
                {mode === 'add' ? 'Add User' : 'Save Changes'}
              </Button>
              {onCancel && (
                <Button type="button" variant="outline" onClick={onCancel}>
                  <X className="h-4 w-4 mr-2" />
                  Cancel
                </Button>
              )}
            </div>
          </form>
        </CardContent>
      </Card>

      <SensorHistoryDialog
        open={showRfidHistory}
        onOpenChange={setShowRfidHistory}
        sensorReadings={sensorReadings}
        type="rfid"
        onSelect={handleRfidHistorySelect}
      />

      <SensorHistoryDialog
        open={showFingerprintHistory}
        onOpenChange={setShowFingerprintHistory}
        sensorReadings={sensorReadings}
        type="fingerprint"
        onSelect={handleFingerprintHistorySelect}
      />

      <AdminAuthDialog
        open={showAdminAuth}
        onOpenChange={setShowAdminAuth}
        onAuthenticate={handleAdminAuth}
        title="Administrator Permission Required"
        description="Enter the administrator password to grant or revoke admin privileges."
      />
    </>
  );
}