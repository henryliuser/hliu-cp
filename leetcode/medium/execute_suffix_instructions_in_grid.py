# https://leetcode.com/contest/weekly-contest-273/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        M = len(s)
        ans = []
        dirs = {'L':(0,-1), 'R':(0,1), 'U':(-1,0), 'D':(1,0)}

        def do(i):
            nonlocal r,c
            cnt = 0
            for j in range(i, M):
                x, y = dirs[s[j]]
                r, c = r+x, c+y
                if 0 <= r < n and 0 <= c < n:
                    cnt += 1
                else:
                    return cnt
            return cnt
        for i in range(M):
            r, c = startPos
            ans += [do(i)]
        return ans

                    
