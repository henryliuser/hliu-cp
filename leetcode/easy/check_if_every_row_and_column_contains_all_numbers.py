# https://leetcode.com/contest/weekly-contest-275/problems/check-if-every-row-and-column-contains-all-numbers/
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        N = len(matrix)
        for r in range(N):
            s1 = set(range(1,N+1))
            s2 = set(range(1,N+1))
            for c in range(N):
                x = matrix[r][c]
                y = matrix[c][r]
                if x not in s1: return False
                if y not in s2: return False
                s1.remove(x)
                s2.remove(y)

        return True
