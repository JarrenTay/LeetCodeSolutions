# ----------------------------------------------------------------------------
# Leetcode problem title: Spiral Matrix
# Leetcode problem number: 54
# Leetcode problem difficulty: Medium
# Solution by: Jarren Tay
# Date: 10/25/19
# Time to solve: 00:25:27 
# ----------------------------------------------------------------------------
# Comments: Took a bit of time getting the algorithm, but it wasnt too slow.
# Got stuck on trying to reverse a list.
# ----------------------------------------------------------------------------
# Takeaway: Read the documentation for a function better lol.
# ----------------------------------------------------------------------------

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0:
            return []
        horizLBound = 0
        horizHBound = len(matrix[0])
        vertLBound = 0
        vertHBound = len(matrix)
        outList = []
        while True:
            if vertLBound != vertHBound:
                outList.extend(matrix[vertLBound][horizLBound:horizHBound])
                vertLBound = vertLBound + 1
            else:
                break
            if horizLBound != horizHBound:
                newMatrix = []
                for index in range(vertLBound, vertHBound):
                    newMatrix.append(matrix[index][horizHBound - 1])
                horizHBound = horizHBound - 1
                outList.extend(newMatrix)
            else:
                break
            if vertLBound != vertHBound:
                outList.extend(matrix[vertHBound - 1][horizLBound:horizHBound][::-1])
                vertHBound = vertHBound - 1
            else:
                break
            if horizLBound != horizHBound:
                newMatrix = []
                for index in range(vertLBound, vertHBound):
                    newMatrix.append(matrix[index][horizLBound])
                horizLBound = horizLBound + 1
                outList.extend(newMatrix[::-1])
            else:
                break
        return outList





