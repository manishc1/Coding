#!/usr/bin/python

import heapq
import sys
import time
        
class LRU():
    def __init__(self, limit=0):
        self.limit = limit
        self.size = 0
        self.heap = []
        self.dict = {}

    def bound(limit):
        if(self.limit <= limit):
            self.limit = limit
        else:
            toDelete = self.size - self.limit
            while(toDelete > 0):
                self.delete()
                toDelete = toDelete - 1

    def set(key, value):
        if(self.size < self.limit):
            heapq.heappush(self.heap, tuple([time]))
        

def getSize():
    try:
        N = raw_input()
    except IOError:
        print "Error accepting buffer size."
        sys.exit()
    
    try:
        isinstance(N, int)
    except ValueError:
        print "Error in value of size."
        sys.exit()

    N = int(N)
    if (N<0 or 1000000<N):
        print "Size out of constraint."
        sys.exit()

    return int(N)

def getBoxes(N, boxes):
    lru = LRU(0)
    i = 0
    while(i < N):
        try:
            line = raw_input()
        except IOError:
            print "Error accepting word."
            sys.exit()
              
        line = line.split()
        if(line[0] == "BOUND"):
            lru.bound(int(line[1]))
        elif(line[0] == "SET"):
            lru.set(line[1], int(line[2]))
        elif(line[0] == "GET"):
            lru.get(line[1])
        elif(line[0] == "DUMB"):
            lru.dump()
        else:
            print "Invalid command."
                sys.exit()
        i = i + 1

def main():
    N = getSize()
    boxes = []
    getBoxes(N, boxes)
    allBoxes = rotateBoxes(N, boxes)
    allBoxes.sort(key=lambda x: x['a'], reverse=True)
    ht = getMaxTowerHeight(allBoxes)
    print ht

# If called from the command line, invoke main()
if __name__ == "__main__":
    main()
