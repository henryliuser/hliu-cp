class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        N = len(obstacles)
        dp = [[0] * 3 for _ in range(N+1)]

        dp[1] = [1,0,1]
        for i in range(2,N+1):
            for j in range(3):
                if obstacles[i-1] == j+1:
                    dp[i][j] = float('inf')
                elif obstacles[i-2] != j+1:
                    dp[i][j] = dp[i-1][j]
                else: q = j
            if obstacles[i-2] == 0: continue
            if obstacles[i-2] == obstacles[i-1]: continue
            dp[i][q] = float('inf')
            for j in range(3):
                if j == q: continue
                dp[i][q] = min(dp[i][q], 1 + dp[i][j])

        return min(dp[N])

                
