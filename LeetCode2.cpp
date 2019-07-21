// ----------------------------------------------------------------------------
// Leetcode problem: 2
// Solution by: Jarren Tay
// Date: 7/21/2019
// Time to solve: 01:31:47
// ----------------------------------------------------------------------------
// Comments: Tripped up on adding a node to the linked list
// I understood pointers, but it was necessary to create a function to add the
// node instead of doing so in the while loop. Maybe there is a way to do it
// within the while loop? It would be faster because the add node function would
// not need to iterate from the beginning. However, I spent an more than an hour
// trying to do that, and making the function was much easier.
// ----------------------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Lists may represent different length integers
        // Pad 0s if on list is shorter
        bool l1Null = false;
        bool l2Null = false;
        ListNode* retNode = new ListNode(-1); // Placeholder value that is removed at the end
        ListNode* trueRetNode;
        ListNode* readl1 = l1;
        ListNode* readl2 = l2;
        int carry;
        unsigned int l1Value;
        unsigned int l2Value;
        // Lists are non-empty, so we don't need to check immediately
        while (!l1Null || !l2Null || (carry != 0))
        {
            l1Value = 0;
            l2Value = 0;

            if (!l1Null)
            {
                l1Value = readl1->val;
            }
            if (!l2Null)
            {
                l2Value = readl2->val;
            }
            
            carry = addNode(retNode, l1Value + l2Value + carry);
            cout << carry;

            if (readl1->next == NULL)
            {
                l1Null = true;
            }
            else
            {
                readl1 = readl1->next;
            }
            
            if (readl2->next == NULL)
            {
                l2Null = true;
            }
            else
            {
                readl2 = readl2->next;
            }
        }
        trueRetNode = retNode->next;
        delete retNode;
        return trueRetNode;
    }
    
    int addNode(ListNode* list, int value) {
        ListNode* listNodePointer = list;
        while (listNodePointer->next != NULL) {
            listNodePointer = listNodePointer->next;
        }
        listNodePointer->next = new ListNode(value % 10);
        return value / 10; // Integer division
    }
};