"""
Write a function that takes two parameters: (1) a String representing a text document and (2) an integer providing the number of items to return. Implement the function such that it returns a list of Strings ordered by word frequency, the most frequently occurring word first.
Assumption: Word is continuous characters [0-9a-zA-Z] case insensitive.
"""

"""
Author: Manish Chavan
"""

"""
Design:
1. Preprocessing  ::  Time=O(max{n, (m log m)}), Space=O(n), n=# words, m=# counts
   Maintain Word To Count Dictionary (Hash) : {word1:count1, word2:count2, ...}  ::  Time=O(n), Space=O(n), n=# words
   Maintain Count To Word Dictionary (Hash) : {count1:{word1a:None, word1b:None, ...}, count2:{word1a:None, word1b:None, ...}, ...}  ::  Time=O(n), Space=O(n), n=# words
   Use count sort to maintain Sorted List of Counts: [count1, count2, ...]  ::  Time=O(m), Space=O(m), m=max counts (never greater than # words)
2. Most Frequent Words  ::  Time=O(k), Space=O(k), k=# of frequent words to return
   Traverse the List of Counts and retreive words corresponding to that counts in CountToWord Dictionary.
"""

#! /usr/bin/python

import string

def countSort(aList, endOfRange):
    """
    Count Sort :: Time=O(m)
    """
    counter = [0] * (endOfRange + 1)
    for i in aList:
      counter[i] += 1
 
    j = 0;
    for i in range(len(counter)):
      while 0 < counter[i]:
        aList[j] = i
        j += 1
        counter[i] -= 1

class WordFrequencies:
    """
    Class to maintain the preprocessed data of the text (document)
    """

    def __init__(self, text = ""):
        """
        Preprocess
        """
        self.wordToCount = {}
        self.countToWord = {}        
        # form list of words (lowercased, stripped of punctuations)
        words = [word.strip(string.punctuation).lower() for word in text.split()]
        maxCount = 0
        for word in words:
            # increment the count of word
            if self.wordToCount.has_key(word):
                count = self.wordToCount[word] + 1
            else:
                count = 1
            self.wordToCount[word] = count
            maxCount = max(maxCount, count)
            # remove word corresponding to (count-1)
            if (count > 1):
                self.countToWord[count-1].pop(word, None)
            # add word to new count
            if (self.countToWord.has_key(count)):
                self.countToWord[count][word] = None
            else:
                temp = {}
                temp[word] = None
                self.countToWord[count] = temp
        # form a sorted list of counts for future linear traversal of counts
        self.countList = self.countToWord.keys()
        countSort(self.countList, maxCount)

    def __repr__(self):
        """
        Easy way to print the object
        """
        return "WordFrequencies (%s , %s , %s)" % (self.wordToCount, self.countToWord, self.countList)
        
    def getMostFrequentWords(self, k):
        """
        Return k most frequent words
        """
        topWords = []
        # if k <= 0, no word is frequent
        if (k < 1):
            return topWords
        # starting from max count, retreive words corresponding to it
        for count in reversed(self.countList):
            for key in self.countToWord[count]:
                topWords.append(key)
                k = k - 1;
                if (k == 0):
                    return topWords
        return topWords


def test(name="No Name", text="", k=0, expected=[]):
    """
    Test template
    """
    wf = WordFrequencies(text)
    if(set(wf.getMostFrequentWords(k)) == set(expected)):
        print "%s Test Successful!" % (name)
    else:
        print "%s Test Failed!" % (name)

def main(text = "", k = 0):
    test("Empty Text", "", 1, [])
    test("Zero Frequent", "This is the text", 0, [])
    test("Hello World", "Hello World", 2, ['hello', 'world'])
    test("Frequency", "Word1 Word2 Word3, Word1 Word2, Word1", 2, ['word1', 'word2'])
    test("Large k", "Word1", 2, ['word1'])

# If called from the command line, invoke main()
if __name__ == "__main__":
    main()
