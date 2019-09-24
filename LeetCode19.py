# ----------------------------------------------------------------------------
# Leetcode problem title: Remove nth node from list
# Leetcode problem number: 19
# Leetcode problem difficulty: Medium
# Solution by: Jarren Tay
# Date: 9/24/2019
# Time to solve: 00:09:02*
# ----------------------------------------------------------------------------
# Comments: I read through the solution before implementing this.
# ----------------------------------------------------------------------------
# Takeaway:
# ----------------------------------------------------------------------------

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        currentNode = head
        count = 1
        while currentNode.next != None:
            count = count + 1
            currentNode = currentNode.next
        currentNode = head
        reiterate = count - n - 1
        if reiterate == -1:
            return head.next
        else:
            for _ in range(count - n - 1):
                currentNode = currentNode.next
            currentNode.next = currentNode.next.next
            return head