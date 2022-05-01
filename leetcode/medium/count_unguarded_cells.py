# https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        A = [[0]*n for _ in range(m)]
        for r,c in guards: A[r][c] = 1
        for r,c in walls:  A[r][c] = 2

        def go(r, c, g):  # return new g state
            x = A[r][c]
            if x == 2: return 0
            if x == 1: g = 1
            elif g: A[r][c] = 3
            return g

        for r in range(m):
            down = range(n)
            up   = range(n-1,-1,-1)
            for loop in [down, up]:
                g = 0
                for c in loop:
                    g = go(r, c, g)

        for c in range(n):
            right = range(m)
            left  = range(m-1,-1,-1)
            for loop in [right, left]:
                g = 0
                for r in loop:
                    g = go(r, c, g)

        ans = 0
        for r in range(m):
            for c in range(n):
                ans += (A[r][c] == 0)
        return ans 
