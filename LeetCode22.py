# ----------------------------------------------------------------------------
# Leetcode problem title: Generate Parentheses
# Leetcode problem number: 22
# Leetcode problem difficulty: Medium
# Solution by: Jarren Tay
# Date: 9/30/2019
# Time to solve: N/A
# ----------------------------------------------------------------------------
# Comments: Had a hard time understanding this one. Use recursion to generate
# all possibilities before hand and add onto it by extending it for one more
# iteration.
# ----------------------------------------------------------------------------
# Takeaway: 
# ----------------------------------------------------------------------------

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return ['']
        ans = []
        for c in range(n):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(n - c - 1):
                    ans.append("({}){}".format(left, right))
        return ans