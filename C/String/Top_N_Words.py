#!/usr/bin/python

import sys

class Words():
    def __init__(self):
        self.dict = {}
        self.inverted = {}

    def add(self, word):
        if self.dict.has_key(word):
            count = self.dict[word]
        else:
            count = 0
        self.dict[word] = count + 1

    def printFrequent(self, k):
        words = []
        prevCount = -1
        for word in sorted(self.dict, key=self.dict.get, reverse=True):
            if (k <= 0):
                break
            if (self.dict[word] != prevCount):
                words = sorted(words)
                length = min(len(words), k)
                for i in range(length):
                    print words[i]
                k = k - length
                prevCount = self.dict[word]
                words = []
                words.append(word)
            else:
                words.append(word)
        if (k > 0):
            words = sorted(words)
            length = min(len(words), k)
            for i in range(length):
                print words[i]
        
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
    if (N<=0 or 300000<=N):
        print "Size out of constraint."
        sys.exit()

    return int(N)

def getWords(N, w):
    word = ""
    i = 0
    while(i < N):
        try:
            word = raw_input()
        except IOError:
            print "Error accepting word."
            sys.exit()
                
        if (len(word) == 0 or len(word) >= 25):
            print "Invalid word."
            sys.exit()
        w.add(word)                        
        i = i + 1

def main():
    N = getSize()
    w = Words()
    getWords(N, w)
    k = getSize()
    w.printFrequent(k)

# If called from the command line, invoke main()
if __name__ == "__main__":
    main()
