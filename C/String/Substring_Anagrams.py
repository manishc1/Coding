#! /usr/bin/python

def getDict(string):
    dict = {}
    for i in range(len(string)):
        count = 0
        if dict.has_key(string[i]):
            count = dict[string[i]] + 1
        else:
            count = 1
        dict[string[i]] = count
    return dict

def getCount(dict, char):
    if dict.has_key(char):
        return dict[char]
    return 0

def inc(dict, char):
    count = 0
    if dict.has_key(char):
        count = dict[char] + 1
    else:
        count = 1
    dict[char] = count    

def dec(dict, char):
    dict[char] = dict[char] - 1

def diff(needleDict, haystackDict, char, increment):
    needleCount = getCount(needleDict, char)
    beforeCount = getCount(haystackDict, char)
    if (increment):
        inc(haystackDict, char)
    else:
        dec(haystackDict, char)
    afterCount = getCount(haystackDict, char)
    if (needleCount == beforeCount and needleCount != afterCount):
        return 1
    if (needleCount != beforeCount and needleCount == afterCount):
        return -1
    return 0

def isSubstringAnagram(haystack, needle):
    needleDict = getDict(needle)
    haystackDict = {}

    diffChars = len(needleDict.keys())
    for i in range(len(haystack)):
        if (i >= len(needle)):
            diffChars = diffChars + diff(needleDict, haystackDict, haystack[i-len(needle)], False)
        diffChars = diffChars + diff(needleDict, haystackDict, haystack[i], True)
        if diffChars == 0:
            print haystack[i-len(needleDict)+1 : i+1]

def main():
    haystack = raw_input('Haystack: ')
    needle = raw_input('Needle: ')
    isSubstringAnagram(haystack, needle)

if __name__ == '__main__':
    main()
