// ----------------------------------------------------------------------------
// Leetcode problem: 3
// Solution by: Jarren Tay
// Date: 7/21/2019
// Time to solve: 00:09:41
// ----------------------------------------------------------------------------
// Comments: I came up with a solution quickly, but it was slower and used more
// memory than most other solutions. I can reduce speed in a couple ways. 
// If my substring stopped because it was the last character in the string, I
// can stop immediately. I can use less memory by not creating a separate
// substring and using offsets. This solution took 00:05:30 to implement.
// I used much less memory, but it's still slower than a lot of solutions.
// 
// A much faster solution would be to place the indices of letters and compare
// them. The tricky part would be if the final substring would contain start
// at the beginning or end at the end of the entire string. 
// Implemented in 02:30:02.
// This solution ended up being slower because of the different cases it had
// to handle. I also need to write better test cases.
//
// I can definitely implement the second solution with a better data structure.
// Also, I can use the sliding window technique instead of repopulating a
// data structure from scratch. Implemented in 00:25:36. I'm rusty lol.
// 
// The next optimization is a better sliding window with indexes. It keeps
// track of the indices of the letters for less reiteration. It's almost what
// I did for my third solution, but a loooot better. Implemented in 00:24:01
//
// Takeaway: Think about data structues. Write good test cases.

/* First solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSub = 0;
        bool repeat = false;
        for (int i = 0; i < s.length(); ++i)
        {
            repeat = false;
            for (int j = i; j < s.length(); ++j)
            {
                string substring = s.substr(i, j - i + 1);
                if (substring.length() > 1)
                {
                    for (int k = 0; k < substring.length() - 1; ++k) {
                        if (s[j] == substring[k])
                        {
                            repeat = true;
                            break;
                        }
                    }
                }
                if (repeat == true)
                {
                    break;
                }
                else
                {
                    if (longestSub < substring.length())
                    {
                        longestSub = substring.length();
                    }
                }
            }
        }
        return longestSub;
    }
};
*/

/* Second solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSub = 0;
        bool repeat = false;
        bool endOfString = false;
        for (int i = 0; i < s.length(); ++i)
        {
            repeat = false;
            for (int j = i; j < s.length(); ++j)
            {
                if (j - i > 0)
                {
                    // the last char should not compare to itself
                    for (int k = i; k < j; ++k) {
                        if (s[j] == s[k])
                        {
                            repeat = true;
                            break;
                        }
                    }
                }
                if (repeat == true)
                {
                    break;
                }
                else
                {
                    if (longestSub < j - i + 1)
                    {
                        longestSub = j - i + 1;
                    }
                }
                if (j == s.length())
                {
                    endOfString = true;
                }
            }
            if (endOfString)
            {
                break;
            }
        }
        return longestSub;
    }
};
*/

/* Third solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // map of vector of ints. An array of vectors of ints would use less space, but not sacrificing readability
        map < char, vector<int> > characterIndices;
        map < char, vector<int> >::iterator ciIterator;
        int maxSubstring = 0;
        int diffCompare = 0;
        pair <int, int> ciPair;

        for (int i = 0; i < s.length(); ++i)
        {
            ciIterator = characterIndices.find(s[i]);
            if (ciIterator == characterIndices.end())
            {
                vector<int> tempVector;
                tempVector.push_back(i);
                characterIndices.insert(pair<char, vector<int> >(s[i], tempVector));
            }
            else
            {
                ciIterator->second.push_back(i);
            }
        }
        // Must be aware of edge cases: all same letter, no string
        if (characterIndices.size() == 0)
        {
            // Empty string
            return 0;
        }
        if (characterIndices.size() == 1)
        {
            // String of only one character
            return 1;
        }

        // If we create pretend there is a character at the beginning and end of the string, and that character matches
        // every character, it simplifies our problem. We don't need to consider the beginning and end of the string as
        // edge cases.
        for (ciIterator = characterIndices.begin(); ciIterator != characterIndices.end(); ++ciIterator)
        {
            // Insert bounds as the begining of the string
            ciIterator->second.insert(ciIterator->second.begin(), -1);
            // Insert bounds as the end of the string
            ciIterator->second.push_back(s.length());
            
            cout << ciIterator->first << endl;
            for (int i = 0; i < ciIterator->second.size(); i++)
            {
                cout << ciIterator->second[i] << "," << endl;
            }
        }
        // Now, the indices of each character has been recorded.
        // The longest substring would be the largest difference between two contiguous indices of a letter that 
        // doesn't fully contain two contiguous indices of a different letter.

        // For each letter
        for (ciIterator = characterIndices.begin(); ciIterator != characterIndices.end(); ++ciIterator)
        {
            // Get the first two contiguous indices
            for (int ci1aIndex = 0; ci1aIndex < ciIterator->second.size() - 1; ++ci1aIndex)
            {
                int ci1a = ciIterator->second[ci1aIndex];
                int ci1b = ciIterator->second[ci1aIndex + 1];

                ciPair = compare(characterIndices, ciIterator, ci1a, ci1b);
                
                diffCompare = ciPair.second - ciPair.first + 1;
                if ((ci1a == ciPair.first && ci1b == ciPair.second) || ciPair.first == -1 || ciPair.second == s.length())
                {
                    diffCompare--;
                }
                cout << "aaa " << ciPair.first << " " << ciPair.second << endl;
                if (diffCompare > maxSubstring)
                {
                    maxSubstring = diffCompare;
                }
            }
        }

        return maxSubstring;
    }

    pair <int, int> compare(map < char, vector<int> > characterIndices, map <char, vector<int> >::iterator ciIterator, const int cia, const int cib)
    {
        map < char, vector<int> >::iterator ciIteratorCompare;
        int ci1a = cia;
        int ci1b = cib;
        pair <int, int> compare1;
        pair <int, int> compare2;
        // Compare the second two contiguous indices
        for (ciIteratorCompare = characterIndices.begin(); ciIteratorCompare != characterIndices.end(); ++ciIteratorCompare)
        {
            if (ciIteratorCompare != ciIterator && ciIteratorCompare->second.size() > 3)
            {
                // Get the second two contiguous indices
                for (int ci2aIndex = 1; ci2aIndex < ciIteratorCompare->second.size() - 2; ++ci2aIndex)
                {
                    int ci2a = ciIteratorCompare->second[ci2aIndex];
                    int ci2b = ciIteratorCompare->second[ci2aIndex + 1];
                    
                    cout << ci1a << "," << ci1b << "," << ci2a << "," << ci2b << "," << endl;
                    if (ci1a <= ci2a && ci1b >= ci2b) // Needs to have equal to because the first/last placeholder chars are the same index
                    {
                        compare1 = compare(characterIndices, ciIterator, ci1a, ci2b - 1);
                        compare2 = compare(characterIndices, ciIterator, ci2a + 1, ci1b);
                        if ((compare1.second - compare1.first >= (compare2.second - compare2.first)))
                        {
                            ci1a = compare1.first;
                            ci1b = compare1.second;
                        }
                        else
                        {
                            ci1a = compare2.first;
                            ci1b = compare2.second;
                        }
                    }
                }
            }
        }
        return pair<int, int>(ci1a, ci1b);
    }
};
*/

/* Fourth solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSub = 0;
        set<char> substringChars;
        int windowBegin = 0;

        for (int windowEnd = 0; (windowEnd < s.length()) && (s.length() - windowBegin >= longestSub); windowEnd++)
        {
            if (substringChars.find(s[windowEnd]) == substringChars.end())
            {
                substringChars.insert(s[windowEnd]);
                if (longestSub < substringChars.size())
                {
                    longestSub = substringChars.size();
                    cout << substringChars.size();
                }
            }
            else
            {
                cout << substringChars.size();
                while (substringChars.find(s[windowEnd]) != substringChars.end())
                {
                    substringChars.erase(substringChars.find(s[windowBegin]));
                    windowBegin++;
                }
                substringChars.insert(s[windowEnd]);
            }
        }
        return longestSub;
    }
};
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSub = 0;
        map<char, int> substringCharIndices;
        map<char, int>::iterator subFind;
        int windowBegin = 0;
        int currWindow = 0;

        for (int windowEnd = 0; (windowEnd < s.length()) && (s.length() - windowBegin >= longestSub); windowEnd++)
        {
            subFind = substringCharIndices.find(s[windowEnd]);
            if (subFind == substringCharIndices.end())
            {
                substringCharIndices.insert(pair<char, int>(s[windowEnd], windowEnd));
            }
            else
            {
                windowBegin = max(windowBegin, subFind->second + 1);
                subFind->second = windowEnd;
            }
            currWindow = windowEnd - windowBegin + 1;
            if (currWindow > longestSub)
            {
                longestSub = currWindow;
            }
        }
        return longestSub;
    }
};