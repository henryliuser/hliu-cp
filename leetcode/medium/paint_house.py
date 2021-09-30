class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        N = len(costs)
        @cache
        def dfs(i, c):
            if i == 0: return costs[0][c]
            ans = float('inf')
            for j in range(3):
                if c == j: continue
                ans = min(ans, dfs(i-1, j))
            return ans + costs[i][c]
        return min(dfs(N-1, c) for c in range(3))
