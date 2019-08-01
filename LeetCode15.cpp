// ----------------------------------------------------------------------------
// Leetcode problem title: 3 Sum
// Leetcode problem number: 15
// Leetcode problem difficulty: Medium
// Solution by: Jarren Tay
// Date: 7/31/2019
// Time to solve: 01:03:08
// ----------------------------------------------------------------------------
// Comments: I got tripped up by creating confusing code. I used a slightly
// strange naming convention, and chose to write length one lined if statements
// That tripped me up because I wasn't sure that the effect was what I intended
// My solution has the same big O as other solutions that I saw, however, it
// was much slower than others. This was due to some overhead from using
// unnecessary data structures and not leveraging sorting.
//
// When I get more time, I'll try to implement the faster solution.
// ----------------------------------------------------------------------------
// Takeaway: Write cleaner code 4head. Think about sorting advantages in
// addition to data structures.
// ----------------------------------------------------------------------------

// So in two sum, we would have one number and check if its complement was in
// the set of unique numbers. In this case, I think we iterate through the
// first vector. Add numbers to a set, and iterate through the set, two nums at
// a time. We can take advantage of the set properties with the third number,
// because we'd know what it is.

// We then have to iterate over our solution set to ensure that we don't have
// recurring solutions.

// Set does not work because there can be duplicates of a number.
// A map could be used, and the value equals the occurences of that number.
// Brute force would take a lot of iterations, def not the best way.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map <int, int> numOccurences;
        map <int, int>::iterator mapIt;
        map <int, int>::iterator mapIt2;
        map <int, int>::iterator mapIt3;
        vector < vector<int> > threeSums;
        set < vector<int> > threeSumsSet;
        set < vector<int> >::iterator setIt;

        for (int i = 0; i < nums.size(); ++i)
        {
            mapIt = numOccurences.find(nums[i]);
            if (mapIt == numOccurences.end())
            {
                numOccurences.insert(pair<int, int>(nums[i], 1));
            }
            else
            {
                numOccurences[nums[i]] = numOccurences[nums[i]] + 1;
            }
        }

        int complement;
        int tempNum;
        for (mapIt = numOccurences.begin(); mapIt != numOccurences.end(); mapIt++)
        {
            for (mapIt2 = mapIt; mapIt2 != numOccurences.end(); mapIt2++)
            {
                complement = mapIt->first + mapIt2->first;
                complement = complement * -1;

                mapIt3 = numOccurences.find(complement);
                if (mapIt3 != numOccurences.end())
                {
                    bool enoughOccurences = true;
                    if (mapIt == mapIt2 && mapIt == mapIt3)
                    {
                        enoughOccurences = mapIt->second >= 3;
                    }
                    else
                    {
                        if (mapIt == mapIt2)
                        {
                            enoughOccurences = mapIt->second >= 2;
                        }
                        if (mapIt == mapIt3)
                        {
                            enoughOccurences = mapIt->second >= 2;
                        }
                        if (mapIt2 == mapIt3)
                        {
                            enoughOccurences = mapIt2->second >= 2;
                        }
                    }
                    if (enoughOccurences)
                    {
                        vector <int> tempVect(3, 0);
                        tempVect[0] = mapIt->first;
                        tempVect[1] = mapIt2->first;
                        tempVect[2] = mapIt3->first;
                        if (tempVect[0] > tempVect[1])
                        {
                            tempNum = tempVect[0];
                            tempVect[0] = tempVect[1];
                            tempVect[1] = tempNum;
                        }
                        if (tempVect[1] > tempVect[2])
                        {
                            tempNum = tempVect[1];
                            tempVect[1] = tempVect[2];
                            tempVect[2] = tempNum;
                        }
                        if (tempVect[0] > tempVect[1])
                        {
                            tempNum = tempVect[0];
                            tempVect[0] = tempVect[1];
                            tempVect[1] = tempNum;
                        }
                        threeSumsSet.emplace(tempVect);
                    }
                }
            }
        }

        for (setIt = threeSumsSet.begin(); setIt != threeSumsSet.end(); setIt++)
        {
            threeSums.push_back(*setIt);
        }
        return threeSums;
    }
};