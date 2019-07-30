// ----------------------------------------------------------------------------
// Leetcode problem title: Container With Most Water
// Leetcode problem number: 11
// Solution by: Jarren Tay
// Date: 7/29/2019
// Time to solve: 01:20:02
// ----------------------------------------------------------------------------
// Comments: My original solution was much more complicated and didn't account
// for an edge case. The pitfall here was that I tried to optimize too early,
// and I missed the correct solution. I got a bit too fancy, and it really
// did not pay off. 
//
// Another piece of advice I learned. Programming slowly is because of a lack
// of understanding of the problem, not being a slow typist. Take the time to
// understand the entire problem before trying to code, and the coding will
// occur a lot faster.
//
// Solution 2 was implemented after reading the solution to the problem. It
// only took 00:07:02 to implement. Goes to show how much I needed that piece
// of advice.
// ----------------------------------------------------------------------------
// Takeaway: Understand -> Implement, don't do both at the same time.
// Solutions breed better solutions. Don't try to be too fancy at the get go.
// Changing the naive solution is fast after having a clear understanding of
// the problem.
// ----------------------------------------------------------------------------

// Area is maximized with largest width, and largest height. They can be scored
// by adding them together. They can be further scored by how close the width
// and the height are. Width about equal to height is better than one being
// extremely large.

// Maybe we start from the outer edges, and work inwards? It's a pair of finding
// the tallest that are far apart.

// Maybe create a map of height to position?
// At the same time, populate a set that contains all heights.
// Not necessary because maps are kept in order.
// Start with tallest and work down.
// While checking, determine best case scenarios and if it is possible, we know
// to keep checking.

// Fundamental problem with solution 1. Edge case requires entire rework of algorith,
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        map <int, pair<int, int> > heightToLoc;
        map <int, pair<int, int> >::iterator htlIterator;

        for (int i = 0; i < height.size(); i++)
        {
            htlIterator = heightToLoc.find(height[i]);
            if (htlIterator == heightToLoc.end())
            {
                pair <int, int> tempPair (i, -1);
                heightToLoc.insert(pair< int, pair<int, int> > (height[i], tempPair));
            }
            else
            {
                htlIterator->second.second = i;
            }
        }

        int curArea = 0;
        int lBound = -1;
        int rBound = -1;
        int tempBound = 0;
        int containerHeight = 0;
        int bestCase = 0;
        int nextLower = 0;
        map <int, pair<int, int> >::reverse_iterator rit;

        for (rit = heightToLoc.rbegin(); rit != heightToLoc.rend(); rit++)
        {
            if (lBound == -1) {
                lBound = rit->second.first;
            }
            if (rBound == -1)
            {
                if (rit->second.first != lBound)
                {
                    rBound = rit->second.first;
                }
                else if (rit->second.second != -1)
                {
                    rBound = rit->second.second;
                }

                if (rBound != -1 && rBound < lBound)
                {
                    tempBound = rBound;
                    rBound = lBound;
                    lBound = tempBound;
                }

                if (rBound != -1)
                {
                    containerHeight = rit->first;
                }
            }
            if (rBound != -1 & lBound != -1)
            {
                int minLBound = min(lBound, rit->second.first);
                int maxRBound = max(rBound, rit->second.second);
                maxRBound = max(maxRBound, rit->second.first);
                if ((maxRBound - minLBound) * rit->first > curArea)
                {
                    lBound = minLBound;
                    rBound = maxRBound;
                    containerHeight = rit->first;
                }
            }
            curArea = (rBound - lBound) * containerHeight;
            cout << lBound << " " << rBound << " " << containerHeight << " " << curArea << endl;
        }
        cout << lBound << " " << rBound << " " << containerHeight << endl;
        return curArea;
    }
};
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftBound = 0;
        int rightBound = height.size() - 1;
        int leftWall = height[leftBound];
        int rightWall = height[rightBound];
        int maxArea = calcArea(leftWall, rightWall, leftBound, rightBound);
        int tempArea = 0;
        while (leftBound != rightBound)
        {
            if (leftWall <= rightWall)
            {
                leftBound++;
                leftWall = height[leftBound];
                tempArea = calcArea(leftWall, rightWall, leftBound, rightBound);
                if (tempArea > maxArea)
                {
                    maxArea = tempArea;
                }
            }
            else
            {
                rightBound--;
                rightWall = height[rightBound];
                tempArea = calcArea(leftWall, rightWall, leftBound, rightBound);
                if (tempArea > maxArea)
                {
                    maxArea = tempArea;
                }
            }
            
        }
        return maxArea;
    }

    int calcArea(int leftWall, int rightWall, int leftBound, int rightBound) {
        return min(leftWall, rightWall) * (rightBound - leftBound);
    }
};