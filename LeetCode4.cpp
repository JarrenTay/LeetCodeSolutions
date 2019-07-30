// ----------------------------------------------------------------------------
// Leetcode problem:
// Solution by: Jarren Tay
// Date:
// Time to solve: 0:39:16
// ----------------------------------------------------------------------------
// Comments: 
// ----------------------------------------------------------------------------
// Takeaway:
// ----------------------------------------------------------------------------

// The median of two arrays is the middle most number if the arrays were put
// together. If there are an even amount of numbers, take the average of the
// middle two.

// First get the amount of numbers in each list. Then start at their middles.
// If all of the numbers less than A middle are also less than B middle, and
// all the numbers greater than A middle are also greater than B middle, and
// vice versa, then you have found the middle. Otherwise, go to halfway
// between the current number and the boundary. Repeat this. However, the
// boundary shifts depending on what numbers you are sure are not the median.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int numVals = nums1.size() + nums2.size();
        vector<int> *numsA;
        vector<int> *numsB;
        // numsA will be the bigger one.
        if (nums1.size() >= nums2.size())
        {
            numsA = &nums1;
            numsB = &nums2;
        }
        else
        {
            numsA = &nums2;
            numsB = &nums1;
        }
        
    }

    // checkMedian does not check if the number is positionally in the median, just that value wise could be the median.
    enum checkMedian(vector<int>& numsA, vector<int>& numsB, int index1, char vector1, int index2, char vector2)
    {
        int val1;
        int val2;
        int lval1;
        int lval2;
        int rval1;
        int rval2;
        if (vector1 == 'a')
        {
            if (index1 > 0 && index1 < numsA.size())
            {
                val1 = numsA[index1];
                if (index1 - 1 > 0)
                {
                    lval1 = numsA[index1 - 1];
                }
                else
                {
                    
                }
                
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (index1 > 0 && index1 < numsB.size())
            {
                val1 = numsB[index1];
            }
            else
            {
                return false;
            }
        }
        if (vector2 == 'a')
        {
            if (index2 > 0 && index2 < numsA.size())
            {
                val2 = numsA[index2];
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (index2 > 0 && index2 < numsB.size())
            {
                val2 = numsB[index2];
            }
            else
            {
                return false;
            }
        }

    }
};