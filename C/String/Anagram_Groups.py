"""Given a list of words, group anagrams."""

#! /usr/bin/python

def add(dict, key, val):
    vals = []
    if(dict.has_key(key)):
        vals = dict[key]
    else:
        vals = []
    vals.append(val)
    dict[key] = vals

def groupAnagrams(strings):
    dict = {}
    for s in strings:
        sorteds = ''.join(sorted(s))
        add(dict, sorteds, s)
    strings = [val for val in dict.values()]
    return strings
        

strings = ["car", "star", "war", "arc", "rats"]
print strings
strings = groupAnagrams(strings)
print strings

