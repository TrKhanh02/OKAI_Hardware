import { useState } from 'react';
import { Dialog, DialogContent, DialogHeader, DialogTitle, DialogDescription } from '@/app/components/ui/dialog';
import { Button } from '@/app/components/ui/button';
import { Input } from '@/app/components/ui/input';
import { Grid3X3, Search, X } from 'lucide-react';
import { ScrollArea } from '@/app/components/ui/scroll-area';

export interface User {
  id: number;
  name: string;
  rfidUid?: string;
  fingerprintFid?: string;
  isAdmin?: boolean;
}

interface IdGridProps {
  users: User[];
  onSelectUser: (userId: number) => void;
  maxSlots?: number;
}

export function IdGrid({ users, onSelectUser, maxSlots = 100 }: IdGridProps) {
  const [isOpen, setIsOpen] = useState(false);
  const [searchTerm, setSearchTerm] = useState('');
  const [highlightedSlot, setHighlightedSlot] = useState<number | null>(null);

  const slots = Array.from({ length: maxSlots }, (_, i) => i + 1);

  const handleSearch = () => {
    if (!searchTerm.trim()) {
      setHighlightedSlot(null);
      return;
    }
    
    const foundUser = users.find(user => 
      user.name.toLowerCase().includes(searchTerm.toLowerCase())
    );
    
    if (foundUser) {
      setHighlightedSlot(foundUser.id);
      // Scroll to the slot
      setTimeout(() => {
        const element = document.getElementById(`slot-${foundUser.id}`);
        element?.scrollIntoView({ behavior: 'smooth', block: 'center' });
      }, 100);
    } else {
      setHighlightedSlot(null);
    }
  };

  const clearSearch = () => {
    setSearchTerm('');
    setHighlightedSlot(null);
  };

  const handleSlotClick = (slotId: number) => {
    const user = users.find(u => u.id === slotId);
    if (user) {
      onSelectUser(slotId);
      setIsOpen(false);
    }
  };

  const registeredCount = users.length;
  const availableCount = maxSlots - registeredCount;

  return (
    <>
      <Button
        onClick={() => setIsOpen(true)}
        variant="outline"
        className="w-full md:w-auto"
      >
        <Grid3X3 className="h-4 w-4 mr-2" />
        View ID Grid ({registeredCount}/{maxSlots})
      </Button>

      <Dialog open={isOpen} onOpenChange={setIsOpen}>
        <DialogContent className="max-w-4xl max-h-[90vh] overflow-hidden flex flex-col">
          <DialogHeader>
            <DialogTitle>ID Slot Management</DialogTitle>
            <DialogDescription>
              Manage and assign ID slots to users.
            </DialogDescription>
            <div className="flex gap-2 text-sm mt-2">
              <span className="flex items-center gap-2">
                <div className="w-4 h-4 bg-red-500 rounded" />
                Registered ({registeredCount})
              </span>
              <span className="flex items-center gap-2">
                <div className="w-4 h-4 bg-green-500 rounded" />
                Available ({availableCount})
              </span>
            </div>
          </DialogHeader>

          {/* Search Box */}
          <div className="flex gap-2 mt-4">
            <div className="relative flex-1">
              <Search className="absolute left-3 top-1/2 transform -translate-y-1/2 h-4 w-4 text-gray-400" />
              <Input
                placeholder="Search by user name..."
                value={searchTerm}
                onChange={(e) => setSearchTerm(e.target.value)}
                onKeyDown={(e) => e.key === 'Enter' && handleSearch()}
                className="pl-10 pr-10"
              />
              {searchTerm && (
                <button
                  onClick={clearSearch}
                  className="absolute right-3 top-1/2 transform -translate-y-1/2 text-gray-400 hover:text-gray-600"
                >
                  <X className="h-4 w-4" />
                </button>
              )}
            </div>
            <Button onClick={handleSearch}>Search</Button>
          </div>

          {/* Grid */}
          <ScrollArea className="flex-1 mt-4 pr-4">
            <div className="grid grid-cols-10 gap-2">
              {slots.map(slotId => {
                const user = users.find(u => u.id === slotId);
                const isRegistered = !!user;
                const isHighlighted = highlightedSlot === slotId;

                return (
                  <button
                    key={slotId}
                    id={`slot-${slotId}`}
                    onClick={() => handleSlotClick(slotId)}
                    disabled={!isRegistered}
                    className={`
                      aspect-square rounded flex items-center justify-center
                      text-sm font-semibold transition-all
                      ${isRegistered 
                        ? 'bg-red-500 hover:bg-red-600 text-white cursor-pointer' 
                        : 'bg-green-500 text-white cursor-not-allowed opacity-50'
                      }
                      ${isHighlighted ? 'ring-4 ring-yellow-400 scale-110' : ''}
                    `}
                    title={user ? user.name : `Slot ${slotId} - Available`}
                  >
                    {slotId}
                  </button>
                );
              })}
            </div>
          </ScrollArea>
        </DialogContent>
      </Dialog>
    </>
  );
}