// ----------------------------------------------------------------------------
// Leetcode problem: 5
// Solution by: Jarren Tay
// Date: 7/25/2019
// Time to solve: 00:43:52
// ----------------------------------------------------------------------------
// Comments: Should've been faster. Made a lot of hasty code changes and didn't 
// think through the edge cases. THINK THROUGH THE EDGE CASES. Also, this was 
// the naive solution. What was the better one?
//
// I looked up the solution, apparently I found the reasonably best algorithm.
// There is a Manacher's algorithm that is faster, but not likely to be
// derived on the fly. However, my implementation is still slower than most.
// Let's redo it to remove unnecessary calculations.
// ----------------------------------------------------------------------------
// Takeaway: Think of edge cases. Don't code when tired.
// ----------------------------------------------------------------------------

/*
    First, think of naive solution:
    Get indices of all characters.
    For each character that has more than one index, s... not good idea

    Search for characters that are two in a row, or one char surrounded by
    two of the same char. Put them in a list.
    Afterwards, go to that index and iterate in both directions to see if how
    large of a palindrome it is.

    Improve that solution.
    Create a set of pairs. These pairs contain a... not good idea

    Just implement
 */
/*
class Solution {
public:
    string longestPalindrome(string s) {
        vector< pair< int, int > > palindromes;

        if (s.size() == 0)
        {
            return "";
        }
        else if (s.size() == 1)
        {
            return s.substr(0,1);
        }
        else if (s.size() == 2)
        {
            if (s[0] == s[1])
            {
                return s;
            }
            else
            {
                return s.substr(0,1);
            }
            
        }
        

        for (int index = 0; index < s.length() - 2; ++index)
        {
            if (s[index] == s[index + 1])
            {
                // two in a row
                palindromes.push_back(pair< int, int >(index, index + 1));
            }
            if (s[index + 1] == s[index + 2])
            {
                // two in a row
                palindromes.push_back(pair< int, int >(index + 1, index + 2));
            }
            if (s[index] == s[index + 2])
            {
                // sandwich
                palindromes.push_back(pair< int, int>(index + 1, index + 1));
            }
        }
        // Now we look at the palindrome 'seeds' and examine their length.

        int maxPalindromeLen = 0;
        string maxPalindrome = "";

        if (palindromes.size() == 0)
        {
            return s.substr(0, 1);
        }
        string tempPalindrome = "";
        int iterator = 0;
        int i1 = 0;
        int i2 = 0;
        for (int pIndex = 0; pIndex < palindromes.size(); pIndex++)
        {
            tempPalindrome = "";
            iterator = 0;
            if (palindromes[pIndex].first != palindromes[pIndex].second)
            {
                // This was two in a row
                i1 = palindromes[pIndex].first;
                i2 = palindromes[pIndex].second;
                tempPalindrome.push_back(s[i1]);
                tempPalindrome.push_back(s[i2]);
                while (i1 - 1 >= 0 && i2 + 1 < s.size())
                {
                    i1--;
                    i2++;
                    if (s[i1] == s[i2])
                    {
                        tempPalindrome.insert(0, 1, s[i1]);
                        tempPalindrome.push_back(s[i2]);
                    }
                    else
                    {
                        break;
                    }
                }
                if (tempPalindrome.size() > maxPalindromeLen)
                {
                    maxPalindromeLen = tempPalindrome.size();
                    maxPalindrome = tempPalindrome;
                }
            }
            else
            {
                // Sandwich
                i1 = palindromes[pIndex].first;
                i2 = palindromes[pIndex].second;
                tempPalindrome.push_back(s[i1]);
                while (i1 - 1 >= 0 && i2 + 1 < s.size())
                {
                    i1--;
                    i2++;
                    if (s[i1] == s[i2])
                    {
                        tempPalindrome.insert(0, 1, s[i1]);
                        tempPalindrome.push_back(s[i2]);
                    }
                    else
                    {
                        break;
                    }
                }
                if (tempPalindrome.size() > maxPalindromeLen)
                {
                    maxPalindromeLen = tempPalindrome.size();
                    maxPalindrome = tempPalindrome;
                }
            }
            // check to see if indices are valid
        }
        return maxPalindrome;
    }
};
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
        {
            return "";
        }
        if (s.size() == 1)
        {
            return s;
        }

        int start = 0;
        int end = 0;
        int tempLength1 = 0;
        int tempLength2 = 0;

        for (int index = 0; index < s.length(); index++)
        {
            tempLength1 = expand(index, index, s);
            tempLength2 = expand(index, index + 1, s);
            if (tempLength1 > end - start)
            {
                start = index - tempLength1 / 2;
                end = index + tempLength1 / 2;
            }
            if (tempLength2 > end - start)
            {
                start = index + 1 - tempLength2 / 2;
                end = index + tempLength2 / 2;
            }
        }
        return s.substr(start, end - start + 1);
        // Now we look at the palindrome 'seeds' and examine their length.
    }
private:
    int expand(const int left, const int right, const string s)
    {
        int lIndex = left;
        int rIndex = right;
        int len = 0;
        while (lIndex >= 0 && rIndex < s.size())
        {
            if (s[lIndex] == s[rIndex])
            {
                len = rIndex - lIndex + 1;
                lIndex--;
                rIndex++;
            }
            else
            {
                break;
            }
            
        }
        return len;
    }
};