#!/usr/bin/python

import sys
        
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
    if (N<0 or 20<N):
        print "Size out of constraint."
        sys.exit()

    return int(N)

def getBoxes(N, boxes):
    box = {}
    i = 0
    while(i < N):
        try:
            line = raw_input()
        except IOError:
            print "Error accepting word."
            sys.exit()
              
        line = line.split()
        box['i'] = i
        box['h'] = int(line[0])
        box['l'] = int(line[1])
        box['w'] = int(line[2])
        box['a'] = box['l'] * box['w']
        boxes.append(box)
        i = i + 1

def rotateBoxes(N, boxes):
    allBoxes = []
    box = {}
    for i in range(N):
        # Copy the original box
        allBoxes.append(boxes[i])

        # First rotation of box
        box['i'] = boxes[i]['i']
        box['h'] = boxes[i]['w']
        box['l'] = max(boxes[i]['h'], boxes[i]['l'])
        box['w'] = min(boxes[i]['h'], boxes[i]['l'])
        box['a'] = box['l'] * box['w']
        allBoxes.append(box)
 
        # Second rotation of box
        box['i'] = boxes[i]['i']
        box['h'] = boxes[i]['l']
        box['l'] = max(boxes[i]['h'], boxes[i]['w'])
        box['w'] = min(boxes[i]['h'], boxes[i]['w'])
        box['a'] = box['l'] * box['w']
        allBoxes.append(box)

    return allBoxes

def getMaxTowerHeight(allBoxes):
    msh = [];
    print allBoxes
    for i in range(len(allBoxes)):
        msh.append([allBoxes[i]['h'], [allBoxes[i]['i']]])
 
    # Compute optimized msh values in memoized
    for i in range(len(allBoxes)):
        for j in range(i):
            print msh
            if (allBoxes[i]['w'] <= allBoxes[j]['w'] and allBoxes[i]['l'] <= allBoxes[j]['l'] and msh[i][0] < msh[j][0] + allBoxes[i]['h'] and allBoxes[i]['i'] not in msh[j][1]):
                msh[i][0] = msh[j][0] + allBoxes[i]['h']
                msh[i][1] = msh[j][1]
                msh[i][1].append(allBoxes[i]['i'])
 
     # Pick maximum of all msh values
    max = -1;
    for i in range(len(allBoxes)):
        if ( max < msh[i][0] ):
            max = msh[i][0];
 
    return max;

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
