// ----------------------------------------------------------------------------
// Leetcode problem title: Roman to Integer
// Leetcode problem number: 13
// Leetcode problem difficulty: Easy
// Solution by: Jarren Tay
// Date: 7/30/2019
// Time to solve: 00:10:36
// ----------------------------------------------------------------------------
// Comments: SO CLOSE TO HAVING CODE COMPILE FIRST TRY. I wrote index i instead
// of int i in my for loop :/. Good effort, good job of understanding the
// full problem before coding it. It was an easy difficulty, so good thing it
// felt easy.
//
// Run time and space usage was better than average.
// ----------------------------------------------------------------------------
// Takeaway: Improving?
// ----------------------------------------------------------------------------

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        char curChar = ' ';
        for (int i = 0; i < s.length(); ++i)
        {
            curChar = s[i];
            if (curChar == 'I')
            {
                if (i + 1 < s.length())
                {
                    if (s[i + 1] == 'V')
                    {
                        value = value + 4;
                        i++;
                    }
                    else if (s[i + 1] == 'X')
                    {
                        value = value + 9;
                        i++;
                    }
                    else
                    {
                        value = value + 1;
                    }
                }
                else
                {
                    value = value + 1;
                }
            }
            else if (curChar == 'V')
            {
                value = value + 5;
            }
            else if (curChar == 'X')
            {
                if (i + 1 < s.length())
                {
                    if (s[i + 1] == 'L')
                    {
                        value = value + 40;
                        i++;
                    }
                    else if (s[i + 1] == 'C')
                    {
                        value = value + 90;
                        i++;
                    }
                    else
                    {
                        value = value + 10;
                    }
                }
                else
                {
                    value = value + 10;
                }
            }
            else if (curChar == 'L')
            {
                value = value + 50;
            }
            else if (curChar == 'C')
            {
                if (i + 1 < s.length())
                {
                    if (s[i + 1] == 'D')
                    {
                        value = value + 400;
                        i++;
                    }
                    else if (s[i + 1] == 'M')
                    {
                        value = value + 900;
                        i++;
                    }
                    else
                    {
                        value = value + 100;
                    }
                }
                else
                {
                    value = value + 100;
                }
            }
            else if (curChar == 'D')
            {
                value = value + 500;
            }
            else
            {
                value = value + 1000;
            }
            
        }
        return value;
    }
};