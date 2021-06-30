# O(MN) time, O(N) space
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        M, N = len(dungeon), len(dungeon[0])
        dp = [[float('inf')] * (N+1) for _ in range(2)]

        dp[M%2][N-1] = 1
        for r in range(M-1, -1, -1):
            t = r % 2
            nt = not t
            for c in range(N-1, -1, -1):
                d = dungeon[r][c]
                dp[t][c] = min(dp[nt][c], dp[t][c+1]) - d
                dp[t][c] = max(dp[t][c], 1)
        return dp[0][0]

# O(MN) time, O(MN) space
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        M, N = len(dungeon), len(dungeon[0])
        dp = [[float('inf')] * (N+1) for _ in range(M+1)]

        dp[M][N-1] = 1
        for r in range(M-1, -1, -1):
            for c in range(N-1, -1, -1):
                d = dungeon[r][c]
                dp[r][c] = min(dp[r+1][c], dp[r][c+1]) - d
                dp[r][c] = max(dp[r][c], 1)
        return dp[0][0]
