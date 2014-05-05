#!/usr/bin/python

import sys

class CircularBuffer():
    def __init__(self, N=0, buffer=[], front=-1, back=-1):
        self.N = N
        self.buffer = [""]*self.N
        self.front = front
        self.back = back
        self.count = 0

    def isFull(self):
        if ((self.back+1)%self.N == self.front):
            return True
        return False

    def isEmpty(self):
        if (self.front == -1):
            return True
        return False

    def add(self, element):
        if (self.isEmpty()):
            self.front = 0
            self.back = 0
            self.count = self.count + 1
        elif(self.isFull()):
            self.front = (self.front + 1) % self.N
            self.back = (self.back + 1) % self.N            
        else:
            self.back = (self.back + 1) % self.N
            self.count = self.count + 1
        self.buffer[self.back] = element

    def remove(self):
        if (self.isEmpty()):
            printf("Buffer underflow.")
            sys.exit()
        if (self.back == self.front):
            self.back = -1
            self.front = -1
        else:
            self.front = (self.front + 1) % self.N
        self.count = self.count - 1                    
        
    def list(self):
        if(self.front == -1):
            return
        i = self.front
        while(i != self.back):
            print self.buffer[i]
            i = (i+1) % self.N
        print self.buffer[i]

    def getCount(self):
        return self.count

def getSize():
    try:
        N = raw_input()
    except IOError:
        print "Error accepting buffer size."
        sys.exit()
    
    try:
        int(N)
    except ValueError:
        print "Error in value of size."
        sys.exit()

    N = int(N)
    if (N<0 or 10000<N):
        print "Size out of constraint."
        sys.exit()

    return int(N)

def isValidCommand(command):
    if (len(command) == 0 or len(command) == 2 or len(command) > 20000000):
        return False
    if (command[0] == 'A' or command[0] == 'R'):
        if (command[1] == " " and int(command.split(' ', 1)[1])):
            return True
        return False
    if (len(command) == 1 and (command[0] == 'L' or command[0] == 'Q')):
        return True
    return False

def getCommands(cb):
    command = ""
    count = 0
    while(count <= 50000):
        try:
            command = raw_input()
        except IOError:
            print "Error accepting command."
            sys.exit()
                
        if  not(isValidCommand(command)):
            print "Invalid command."
            sys.exit()
                        
        count = count + 1
                        
        if(command[0] == 'A'):
            i = int(command.split(' ', 1)[1])
            while(i > 0):
                try:
                    element = raw_input()
                except IOError:
                    print "Error accepting element."
                    sys.exit()

                if (len(element) >= 20000000):
                    print "Out of bound input."
                    sys.exit()
                
                cb.add(element)
                i = i - 1

        elif(command[0] == 'R'):
            i = int(command.split(' ', 1)[1])
            if (i > cb.getCount()):
                print "More removals."
                sys.exit()

            while(i > 0):
                cb.remove()
                i = i - 1
            
        elif(command[0] == 'L'):
            cb.list()
        elif(command[0] == 'Q'):
            break

def main():
    N = getSize()
    cb = CircularBuffer(N)
    getCommands(cb)
    cb.list

# If called from the command line, invoke main()
if __name__ == "__main__":
    main()
