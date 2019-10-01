# ----------------------------------------------------------------------------
# Leetcode problem title: Merging Two Sorted Lists
# Leetcode problem number: 21
# Leetcode problem difficulty: Easy
# Solution by: Jarren Tay
# Date: 9/24/2019
# Time to solve: 00:11:15
# ----------------------------------------------------------------------------
# Comments: Easy problem. Failed the first time because of an oversight on a
# possible test case. Also almost missed a submission from forgetting a mental
# note
# ----------------------------------------------------------------------------
# Takeaway: Take notes, read them, and think of edge cases
# ----------------------------------------------------------------------------

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        node1 = l1
        node2 = l2

        head = ListNode
        curr = head

        while True:
            if node1 == None:
                curr.next = node2
                break
            if node2 == None:
                curr.next = node1
                break
            if node1.val < node2.val:
                curr.next = node1
                node1 = node1.next
            else:
                curr.next = node2
                node2 = node2.next
            curr = curr.next
        return head.next
                
            
