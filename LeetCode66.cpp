// ----------------------------------------------------------------------------
// Leetcode problem title: Plus One
// Leetcode problem number: 66
// Leetcode problem difficulty: Easy
// Solution by: Jarren Tay
// Date: 10/25/19
// Time to solve: 00:05:34
// ----------------------------------------------------------------------------
// Comments: Didn't pay attention to what the function was supposed to return.
// ----------------------------------------------------------------------------
// Takeaway:
// ----------------------------------------------------------------------------

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool done = false;
        int currIndex = digits.size() - 1;
        while (!done) {
            if (currIndex != -1) {
                digits[currIndex] = digits[currIndex] + 1;
                if (digits[currIndex] == 10) {
                    digits[currIndex] = 0;
                    currIndex = currIndex - 1;
                } else {
                    done = true;
                }
            } else {
                digits.insert(digits.begin(), 1);
                done = true;
            }
        }
        return digits;
    }
};