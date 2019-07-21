// ----------------------------------------------------------------------------
// Leetcode problem: 1
// Solution by: Jarren Tay
// Date: 7/21/2019
// Time to solve: 00:08:10
// ----------------------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Numbers may be negative, so the numbers that are larger than the target may still be usable

        vector<int> indices;
        for (int index1 = 0; index1 < nums.size(); ++index1)
        {
            for (int index2 = index1 + 1; index2 < nums.size(); ++index2)
            {
                if (nums[index1] + nums[index2] == target) {
                    indices.push_back(index1);
                    indices.push_back(index2);
                    return indices;
                }
            }
        }
        indices.push_back(0);
        indices.push_back(1);
        return indices;
    }
};