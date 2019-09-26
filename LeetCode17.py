"""
// ----------------------------------------------------------------------------
// Leetcode problem title: Letter Combinations of a Phone Number
// Leetcode problem number: 17
// Leetcode problem difficulty: Medium
// Solution by: Jarren Tay
// Date: 9/22/2019
// Time to solve: 00:21:55
// ----------------------------------------------------------------------------
// Comments: Small python tricks make a big runtime difference. Do people
// even care about python runtime?
// ----------------------------------------------------------------------------
// Takeaway:
// ----------------------------------------------------------------------------
"""
class Solution(object):
    
    numLookup = dict()

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        retList = []
        for number in digits:
            lookList = self.numLookup[number]
            if (len(retList) == 0):
                for letter in lookList:
                    retList.append(letter)
            else:
                newList = []
                for letter in lookList:
                    for combo in retList:
                        newList.append(combo + letter)
                retList = newList
                
        return retList
    
    def __init__(self):
        self.numLookup['2'] = ['a', 'b', 'c']
        self.numLookup['3'] = ['d', 'e', 'f']
        self.numLookup['4'] = ['g', 'h', 'i']
        self.numLookup['5'] = ['j', 'k', 'l']
        self.numLookup['6'] = ['m', 'n', 'o']
        self.numLookup['7'] = ['p', 'q', 'r', 's']
        self.numLookup['8'] = ['t', 'u', 'v']
        self.numLookup['9'] = ['w', 'x', 'y', 'z']

