#!/usr/bin/python

import sys
        
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
    if (N<2 or 1000<N):
        print "Size out of constraint."
        sys.exit()

    return int(N)

def getNumbers(N, ip):
    number = ""
    i = 0
    while(i < N):
        try:
            number = raw_input()
        except IOError:
            print "Error accepting word."
            sys.exit()
                
        if (isinstance(number, int)):
            print "Invalid word."
            sys.exit()
        ip.append(int(number))                        
        i = i + 1

def getOP(N, ip):
    prev = 1
    nxt = [1]*N
    for i in reversed(range(N-1)):
        nxt[i] = nxt[i+1] * ip[i+1]
    for i in range(N):
        print prev * nxt[i]
        prev = prev * ip[i]

def main():
    N = getSize()
    ip = []
    getNumbers(N, ip)
    getOP(N, ip)

# If called from the command line, invoke main()
if __name__ == "__main__":
    main()
