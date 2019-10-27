# ----------------------------------------------------------------------------
# Leetcode problem title: Maximum Subarray
# Leetcode problem number: 53
# Leetcode problem difficulty: Easy
# Solution by: Jarren Tay
# Date: 10/25/19
# Time to solve: N/A
# ----------------------------------------------------------------------------
# Comments: I read the solution to this problem before submitting it.
# This method is really fast. DP ish
# ----------------------------------------------------------------------------
# Takeaway: 
# ----------------------------------------------------------------------------

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxNum = nums[0]
        lastSum = 0

        for num in nums:
            lastSum = num + (max(lastSum, 0))
            if lastSum > maxNum:
                maxNum = lastSum
        
        return maxNum