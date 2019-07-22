// ----------------------------------------------------------------------------
// Leetcode problem: 1
// Solution by: Jarren Tay
// Date: 7/21/2019
// Time to solve: 00:08:10
// ----------------------------------------------------------------------------
// Comments: The brute force was easy to come up with. My solution performed well
// in terms of memory. However, the run time could potentially be faster. Instead
// of iterating over the possible combinations of numbers, I can keep track of
// each number, and search for the complement number in a hash table.
// Solution two took 00:09:27 to implement.
//
// Takeaway: Keep data structures in mind. De-rust!

/* Solution One
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
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Numbers may be negative, so the numbers that are larger than the target may still be usable

        map<int, int> indices;
        vector<int> retVector;

        for (int index = 0; index < nums.size(); ++index)
        {
            if (indices.find(target - nums[index]) != indices.end())
            {
                retVector.push_back(indices[target - nums[index]]);
                retVector.push_back(index);
                break;
            }
            indices.insert(pair(nums[index], index));
        }
        return retVector;
    }
};