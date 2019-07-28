// ----------------------------------------------------------------------------
// Leetcode problem title: String to Interger atoi
// Leetcode problem number: 9
// Solution by: Jarren Tay
// Date: 7/28/2019
// Time to solve: 00:29:33
// ----------------------------------------------------------------------------
// Comments: I did a lot better about thinking of cases. However, it wouldn't
// hurt to think about it more. I got tripped up by some other cases that I
// just didn't consider. However, run time was average and mem usage was more
// than most. It's probably because I used more variables and made the code
// easier to read. No data structures would have helped much.
// ----------------------------------------------------------------------------
// Takeaway: Did better about thinking of cases. Think more about cases.
// ----------------------------------------------------------------------------

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        int digit = 0;
        int resultingInt = 0;
        int curCharAscii = 0;
        int curNum = 0;
        int negative = 0;
        while (index < str.length())
        {
            if (str[index] != ' ')
            {
                break;
            }
            else
            {
                index++;
            }
        }
        if (str[index] == '-')
        {
            negative = -1;
            index++;
        }
        else if (str[index] == '+')
        {
            negative = 1;
            index++;
        }
        else
        {
            negative = 1;
        }
        while (index < str.length())
        {
            if (str[index] != '0')
            {
                break;
            }
            else
            {
                index++;
            }
        }
        // INT_MIN and INT_MAX are 10 digits. 
        while (digit <= 10)
        {
            if (index < str.length())
            {
                curCharAscii = int(str[index]);
                if (curCharAscii >= int('0') && curCharAscii <= int('9'))
                {
                    curNum = curCharAscii - int('0');
                    if (digit < 9)
                    {
                        resultingInt = resultingInt * 10 + curNum * negative;
                        digit++;
                        index++;
                    }
                    else if (digit == 9)
                    {
                        if (resultingInt < INT_MIN / 10 || resultingInt == INT_MIN / 10 && curNum > 8)
                        {
                            return INT_MIN;
                        }
                        if (resultingInt > INT_MAX / 10 || resultingInt == INT_MAX / 10 && curNum > 7)
                        {
                            return INT_MAX;
                        }
                        resultingInt = resultingInt * 10 + curNum * negative;
                        digit++;
                        index++;
                    }
                    else
                    {
                        if (resultingInt > 0)
                        {
                            return INT_MAX;
                        }
                        else
                        {
                            return INT_MIN;
                        }
                        
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            
        }
        return resultingInt;
    }
};