# ----------------------------------------------------------------------------
# Leetcode problem title: Implement srtStr()
# Leetcode problem number: 28
# Leetcode problem difficulty: Easy 
# Solution by: Jarren Tay
# Date: 9/30/2019
# Time to solve: 00:10:10
# ----------------------------------------------------------------------------
# Comments: Quick algorithm implementation, but I missed a lot of edge cases
# ----------------------------------------------------------------------------
# Takeaway: EDGE CASES
# ----------------------------------------------------------------------------

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        if haystack == "":
            return -1
        needleLen = len(needle)
        haystackLen = len(haystack)
        for i in range(len(haystack)):
            if i + needleLen > haystackLen:
                return -1
            if haystack[i] == needle[0]:
                good = True
                for j in range(needleLen):
                    if haystack[i + j] != needle[j]:
                        good = False
                if good:
                    return i
        return -1