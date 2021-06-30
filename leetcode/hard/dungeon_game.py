class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        M, N = len(dungeon), len(dungeon[0])
        dp = [[float('inf')] * (N+1) for _ in range(M+1)]

        dp[M][N-1], dp[M-1][N] = 1, 1
        for r in range(M-1, -1, -1):
            for c in range(N-1, -1, -1):
                d = dungeon[r][c]
                dp[r][c] = min(dp[r+1][c], dp[r][c+1]) - d
                dp[r][c] = max(dp[r][c], 1)
        return dp[0][0]
