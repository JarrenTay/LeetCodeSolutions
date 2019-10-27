# ----------------------------------------------------------------------------
# Leetcode problem title: Pow(x,n)
# Leetcode problem number: 50
# Leetcode problem difficulty: Medium
# Solution by: Jarren Tay
# Date: 10/23/2019
# Time to solve: 00:12:40
# ----------------------------------------------------------------------------
# Comments: Used dynamic programming for this problem. I got tripped up on
# some edge cases that I should have seen before submitting my code.
# ----------------------------------------------------------------------------
# Takeaway: Test edge cases. And boundary cases.
# ----------------------------------------------------------------------------

class Solution:

    def myPow(self, x: float, n: int) -> float:
        if n >= 0:
            if n in self.multiply:
                return self.multiply[n]
            else:
                if n == 1:
                    self.multiply[1] = x
                    return x
                else:
                    temp = self.myPow(x, n // 2)
                    temp = temp * temp
                    if (n % 2 == 1):
                        temp = temp * x
                    self.multiply[n] = temp
                    return temp
        else:
            return 1 / self.myPow(x, -n)

    
    def __init__(self):
        self.multiply = dict()
        self.multiply[0] = 1.0
