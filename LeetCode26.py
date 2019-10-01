# ----------------------------------------------------------------------------
# Leetcode problem title: Remove Duplicates from Sorted Array
# Leetcode problem number: 26
# Leetcode problem difficulty: Easy
# Solution by: Jarren Tay
# Date: 9/30/2019
# Time to solve: 00:06:19
# ----------------------------------------------------------------------------
# Comments: Did this pretty fast, but didn't read and account for one of the
# problem nuances correctly. And after realizing, I didn't flush it out well.
# ----------------------------------------------------------------------------
# Takeaway: Fully analyze a problem and make sure it's accounted for.
# ----------------------------------------------------------------------------

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        lastNum = None
        deleted = 0
        for i in range(len(nums)):
            if lastNum == nums[i - deleted]:
                nums.pop(i - deleted)
                deleted = deleted + 1
            else:
                lastNum = nums[i - deleted]
        return len(nums)