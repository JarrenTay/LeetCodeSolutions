// ----------------------------------------------------------------------------
// Leetcode problem: 7
// Solution by: Jarren Tay
// Date:7/28/2019
// Time to solve: 01:05:29
// ----------------------------------------------------------------------------
// Comments: I really made some simple implementation mistakes. It would really
// pay off to think through some edge cases before submitting code. There were
// some really basic ones that I thought I was accounting for, but I did so
// incorrectly. I also was slow on implementation.
// ----------------------------------------------------------------------------
// Takeaway: Run through more edge cases. Or any cases. C++ doesn't let you
// overflow.
// ----------------------------------------------------------------------------

// I think mod 10^x will be useful in this problem. Take the mod 10^x and if 
// it's not 0, then add mod 10^x x (10 x len of number - 1).

// Would it be faster to convert this string into an integer, reverse it, and
// convert it back to a int? Probably not, but it would be easier to implement.
// To convert to string, it probably needs to do what we're doing, but with
// more overhead.

// Would it be faster to put each number in a doubly linked list and iterate
// backwards to reconstruct the number? 
// First way requires a lot of multiplication and adding. Second way would
// require twice the iteration? And still needs multiplication and adding.
// I don't think it would be faster

// Running into overflow errors. The easy way would to be use larger types, but
// seems wasteful in memory. Is there a better way?
// 
class Solution {
public:
    int reverse(int x) {
        bool isNegative;
        int remainingX;
        int resultingX = 0;
        int tempResultingX;
        int digitNum = 0;
        int curDigit;
        if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            remainingX = x * -1;
            isNegative = true;
        }
        else
        {
            remainingX = x;
            isNegative = false;
        }

        while (remainingX != 0)
        {
            curDigit = remainingX % 10;
            
            // use negative resulting x since it's got a tiny bit more range
            
            if (digitNum < 9)
            {
                resultingX = resultingX * 10 - curDigit;
                digitNum++;
                remainingX = remainingX / 10;
            }
            else
            {
                if (resultingX > (INT_MIN / 10) || (resultingX == (INT_MIN / 10) && curDigit <= 8))
                {
                    resultingX = resultingX * 10 - curDigit;
                    digitNum++;
                    remainingX = remainingX / 10;
                }
                else
                {
                    cout << resultingX;
                    cout << "a";
                    return 0;
                }
            }
        }
        if (!isNegative)
        {
            // It will overflow when converting to positive
            if (resultingX == INT_MIN)
            {
                cout << "b";
                return 0;
            }
            else
            {
                return resultingX * -1;
            }
        }
        else
        {
            return resultingX;
        }
    }
};