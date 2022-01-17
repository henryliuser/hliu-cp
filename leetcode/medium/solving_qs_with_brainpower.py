# https://leetcode.com/contest/weekly-contest-276/problems/solving-questions-with-brainpower/
class Solution:
    def mostPoints(self, qs: List[List[int]]) -> int:
        @cache
        def dfs(i):
            if i >= len(qs): return 0
            p, b = qs[i]
            a = p + dfs(i+b+1)
            b = dfs(i+1)
            return max(a,b)

        return dfs(0)
