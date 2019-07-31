// ----------------------------------------------------------------------------
// Leetcode problem title: Longest Common Prefix
// Leetcode problem number: 14
// Leetcode problem difficulty: Easy
// Solution by: Jarren Tay
// Date: 7/31/2019
// Time to solve: 00:09:47
// ----------------------------------------------------------------------------
// Comments: Good effort overall. Two things tripped me up from having correct
// first implementation. Difference between string::append() and
// string::push_back(). Difference is obvious, but never used push_back before.
// Forgot to empty my temporary variable.
// Simple mistakes, practice should iron those out.
// Runtime and space was just better than average.
// ----------------------------------------------------------------------------
// Takeaway: Simple mistakes, practice makes perfect.
// ----------------------------------------------------------------------------

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = "";
        string tempPrefix = "";
        for (int i = 0; i < strs.size(); ++i)
        {
            if (i == 0)
            {
                longestPrefix = strs[0];
            }
            else
            {
                tempPrefix = "";
                for (int j = 0; j < min(longestPrefix.length(), strs[i].length()); ++j)
                {
                    if (longestPrefix[j] == strs[i][j])
                    {
                        tempPrefix.push_back(longestPrefix[j]);
                    }
                    else
                    {
                        break;
                    }
                }
                longestPrefix = tempPrefix;
            }
        }
        return longestPrefix;
    }
};