# ----------------------------------------------------------------------------
# Leetcode problem title: Valid Parentheses
# Leetcode problem number: 20
# Leetcode problem difficulty: Easy
# Solution by: Jarren Tay
# Date: 9/24/2019
# Time to solve: 00:08:12
# ----------------------------------------------------------------------------
# Comments: Overall easy problem. I knew the currect data structure to use.
# However, it didnt run through the code to make sure that I was implementing
# what was in my head properly. It took multiple tries to get the solution
# ----------------------------------------------------------------------------
# Takeaway: Make sure I'm handling all of the cases.
# ----------------------------------------------------------------------------

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for character in s:
            if character == '{':
                stack.append('}')
            elif character == '[':
                stack.append(']')
            elif character == '(':
                stack.append(')')
            elif len(stack) > 0:
                if stack.pop() != character:
                    return False
            else:
                return False
        if len(stack) == 0:
            return True



