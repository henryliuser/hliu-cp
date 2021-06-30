class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        dp = [[float('inf')] * (N+1) for _ in range(2)]
        dp[0][1] = 0
        for r in range(1, M+1):
            t = r % 2   # current row
            nt = not t  # previous row
            for c in range(1, N+1):
                x = grid[r-1][c-1]
                dp[t][c] = min(dp[nt][c], dp[t][c-1]) + x
        return dp[M%2][N]
