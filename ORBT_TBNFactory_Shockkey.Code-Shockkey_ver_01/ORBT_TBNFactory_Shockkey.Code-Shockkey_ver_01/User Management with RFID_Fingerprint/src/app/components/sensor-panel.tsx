import { useState, useEffect } from 'react';
import { Button } from '@/app/components/ui/button';
import { Card, CardContent, CardHeader, CardTitle } from '@/app/components/ui/card';
import { Badge } from '@/app/components/ui/badge';
import { Fingerprint, CreditCard, RefreshCw, Save, Loader2 } from 'lucide-react';

export interface SensorReading {
  uid?: string;
  fid?: string;
  timestamp: number;
}

interface SensorPanelProps {
  onSensorData: (data: { uid?: string; fid?: string }) => void;
  sensorReadings: SensorReading[];
  compact?: boolean;
  targetIdSlot?: number;
}

export function SensorPanel({ onSensorData, sensorReadings, compact = false, targetIdSlot: propTargetIdSlot }: SensorPanelProps) {
  const [rfidScanning, setRfidScanning] = useState(false);
  const [rfidData, setRfidData] = useState<string>('');
  const [fingerprintScanning, setFingerprintScanning] = useState(false);
  const [fingerprintScans, setFingerprintScans] = useState<number>(0);
  const [fingerprintData, setFingerprintData] = useState<string>('');

  // Use the target ID slot from props, default to 1
  const targetIdSlot = propTargetIdSlot || 1;

  // Simulate RFID scanning
  const startRfidScan = () => {
    setRfidScanning(true);
    setTimeout(() => {
      const uid = Math.random().toString(16).substring(2, 10).toUpperCase();
      setRfidData(uid);
      setRfidScanning(false);
    }, 2000);
  };

  const saveRfidData = () => {
    onSensorData({ uid: rfidData });
    // Keep the data visible after save
  };

  const refreshRfid = () => {
    setRfidData('');
    startRfidScan();
  };

  // Simulate fingerprint enrollment with ID slot matching
  const startFingerprintEnroll = () => {
    setFingerprintScanning(true);
    setFingerprintScans(0);
    setFingerprintData('');
    
    // Simulate 4 scans
    const scanInterval = setInterval(() => {
      setFingerprintScans(prev => {
        const newCount = prev + 1;
        if (newCount >= 4) {
          clearInterval(scanInterval);
          // Generate FID that matches the target ID slot (encode slot number in FID)
          const slotHex = targetIdSlot.toString(16).padStart(2, '0').toUpperCase();
          const randomPart = Math.random().toString(16).substring(2, 8).toUpperCase();
          const fid = slotHex + randomPart;
          setFingerprintData(fid);
          setFingerprintScanning(false);
        }
        return newCount;
      });
    }, 1500);
  };

  const saveFingerprintData = () => {
    onSensorData({ fid: fingerprintData });
    // Keep the data visible after save
  };

  const refreshFingerprint = () => {
    setFingerprintData('');
    setFingerprintScans(0);
    startFingerprintEnroll();
  };

  if (compact) {
    return (
      <div className="space-y-3">
        {/* RFID Section */}
        <Card>
          <CardHeader className="pb-3">
            <CardTitle className="text-sm flex items-center gap-2">
              <CreditCard className="h-4 w-4" />
              RFID Scanner
            </CardTitle>
          </CardHeader>
          <CardContent className="space-y-2">
            {rfidData && (
              <div className="p-2 bg-green-50 border border-green-200 rounded text-sm">
                <span className="font-mono">{rfidData}</span>
              </div>
            )}
            <div className="flex gap-2">
              <Button
                size="sm"
                onClick={startRfidScan}
                disabled={rfidScanning || !!rfidData}
                className="flex-1"
              >
                {rfidScanning ? (
                  <>
                    <Loader2 className="h-3 w-3 mr-1 animate-spin" />
                    Scanning...
                  </>
                ) : (
                  'Scan RFID'
                )}
              </Button>
              {rfidData && (
                <>
                  <Button size="sm" onClick={saveRfidData} variant="default">
                    <Save className="h-3 w-3" />
                  </Button>
                  <Button size="sm" onClick={refreshRfid} variant="outline">
                    <RefreshCw className="h-3 w-3" />
                  </Button>
                </>
              )}
            </div>
          </CardContent>
        </Card>

        {/* Fingerprint Section */}
        <Card>
          <CardHeader className="pb-3">
            <CardTitle className="text-sm flex items-center gap-2">
              <Fingerprint className="h-4 w-4" />
              Fingerprint Scanner
            </CardTitle>
          </CardHeader>
          <CardContent className="space-y-2">
            {fingerprintScanning && (
              <div className="flex items-center gap-2 p-2 bg-blue-50 border border-blue-200 rounded text-sm">
                <Loader2 className="h-3 w-3 animate-spin" />
                <span>Scan {fingerprintScans}/4</span>
              </div>
            )}
            {fingerprintData && (
              <div className="p-2 bg-green-50 border border-green-200 rounded text-sm">
                <span className="font-mono">{fingerprintData}</span>
              </div>
            )}
            <div className="flex gap-2">
              <Button
                size="sm"
                onClick={startFingerprintEnroll}
                disabled={fingerprintScanning || !!fingerprintData}
                className="flex-1"
              >
                {fingerprintScanning ? 'Enrolling...' : 'Enroll'}
              </Button>
              {fingerprintData && (
                <>
                  <Button size="sm" onClick={saveFingerprintData} variant="default">
                    <Save className="h-3 w-3" />
                  </Button>
                  <Button size="sm" onClick={refreshFingerprint} variant="outline">
                    <RefreshCw className="h-3 w-3" />
                  </Button>
                </>
              )}
            </div>
          </CardContent>
        </Card>
      </div>
    );
  }

  return (
    <div className="grid md:grid-cols-2 gap-4">
      {/* RFID Section */}
      <Card>
        <CardHeader>
          <CardTitle className="flex items-center gap-2">
            <CreditCard className="h-5 w-5" />
            RFID Scanner
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          {rfidData && (
            <div className="p-3 bg-green-50 border border-green-200 rounded">
              <p className="text-sm text-gray-600 mb-1">UID:</p>
              <p className="font-mono font-semibold">{rfidData}</p>
            </div>
          )}
          <div className="flex gap-2">
            <Button
              onClick={startRfidScan}
              disabled={rfidScanning || !!rfidData}
              className="flex-1"
            >
              {rfidScanning ? (
                <>
                  <Loader2 className="h-4 w-4 mr-2 animate-spin" />
                  Scanning...
                </>
              ) : (
                'Activate Scan'
              )}
            </Button>
          </div>
          {rfidData && (
            <div className="flex gap-2">
              <Button onClick={saveRfidData} className="flex-1">
                <Save className="h-4 w-4 mr-2" />
                Save UID
              </Button>
              <Button onClick={refreshRfid} variant="outline">
                <RefreshCw className="h-4 w-4 mr-2" />
                Rescan
              </Button>
            </div>
          )}
        </CardContent>
      </Card>

      {/* Fingerprint Section */}
      <Card>
        <CardHeader>
          <CardTitle className="flex items-center gap-2">
            <Fingerprint className="h-5 w-5" />
            Fingerprint Scanner
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          {fingerprintScanning && (
            <div className="p-3 bg-blue-50 border border-blue-200 rounded flex items-center gap-3">
              <Loader2 className="h-5 w-5 animate-spin text-blue-600" />
              <div>
                <p className="font-semibold">Enrolling...</p>
                <p className="text-sm text-gray-600">Scan {fingerprintScans}/4 completed</p>
              </div>
            </div>
          )}
          {fingerprintData && (
            <div className="p-3 bg-green-50 border border-green-200 rounded">
              <p className="text-sm text-gray-600 mb-1">FID:</p>
              <p className="font-mono font-semibold">{fingerprintData}</p>
            </div>
          )}
          <div className="flex gap-2">
            <Button
              onClick={startFingerprintEnroll}
              disabled={fingerprintScanning || !!fingerprintData}
              className="flex-1"
            >
              {fingerprintScanning ? 'Enrolling...' : 'Enroll Fingerprint'}
            </Button>
          </div>
          {fingerprintData && (
            <div className="flex gap-2">
              <Button onClick={saveFingerprintData} className="flex-1">
                <Save className="h-4 w-4 mr-2" />
                Save FID
              </Button>
              <Button onClick={refreshFingerprint} variant="outline">
                <RefreshCw className="h-4 w-4 mr-2" />
                Restart
              </Button>
            </div>
          )}
        </CardContent>
      </Card>
    </div>
  );
}