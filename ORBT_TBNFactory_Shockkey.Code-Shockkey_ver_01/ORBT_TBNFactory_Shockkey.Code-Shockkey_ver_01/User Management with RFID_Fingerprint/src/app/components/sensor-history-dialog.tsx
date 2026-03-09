import {
  Dialog,
  DialogContent,
  DialogDescription,
  DialogHeader,
  DialogTitle,
} from '@/app/components/ui/dialog';
import { Button } from '@/app/components/ui/button';
import { SensorReading } from './sensor-panel';
import { formatDistanceToNow } from 'date-fns';
import { CreditCard, Fingerprint } from 'lucide-react';

interface SensorHistoryDialogProps {
  open: boolean;
  onOpenChange: (open: boolean) => void;
  sensorReadings: SensorReading[];
  type: 'rfid' | 'fingerprint';
  onSelect: (value: string) => void;
}

export function SensorHistoryDialog({
  open,
  onOpenChange,
  sensorReadings,
  type,
  onSelect,
}: SensorHistoryDialogProps) {
  // Get the 3 most recent readings of the specified type
  const readings = sensorReadings
    .filter(reading => type === 'rfid' ? reading.uid : reading.fid)
    .slice(0, 3);

  const title = type === 'rfid' ? 'Recent RFID Scans' : 'Recent Fingerprint Scans';
  const Icon = type === 'rfid' ? CreditCard : Fingerprint;

  return (
    <Dialog open={open} onOpenChange={onOpenChange}>
      <DialogContent>
        <DialogHeader>
          <DialogTitle className="flex items-center gap-2">
            <Icon className="h-5 w-5" />
            {title}
          </DialogTitle>
          <DialogDescription>
            Select a recent scan to use
          </DialogDescription>
        </DialogHeader>
        <div className="space-y-2 py-4">
          {readings.length === 0 ? (
            <p className="text-sm text-gray-500 text-center py-8">
              No recent scans available
            </p>
          ) : (
            readings.map((reading, index) => {
              const value = type === 'rfid' ? reading.uid : reading.fid;
              const timeAgo = formatDistanceToNow(reading.timestamp, { addSuffix: true });
              
              return (
                <Button
                  key={index}
                  variant="outline"
                  className="w-full justify-between h-auto py-3"
                  onClick={() => {
                    if (value) {
                      onSelect(value);
                      onOpenChange(false);
                    }
                  }}
                >
                  <div className="text-left">
                    <p className="font-mono font-semibold">{value}</p>
                    <p className="text-xs text-gray-500">{timeAgo}</p>
                  </div>
                  <span className="text-xs text-gray-400">#{index + 1}</span>
                </Button>
              );
            })
          )}
        </div>
      </DialogContent>
    </Dialog>
  );
}