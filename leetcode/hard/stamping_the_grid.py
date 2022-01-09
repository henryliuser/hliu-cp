class Solution:
    def possibleToStamp(self, grid: List[List[int]], h: int, w: int) -> bool:
            M, N = len(grid), len(grid[0])

            def build(mtx):
                dp = [[0] * (N+1) for _ in range(M+1)]
                for i in range(1, M + 1):
                    for j in range(1, N + 1):
                        v = mtx[i-1][j-1]
                        top = dp[i-1][j]
                        left = dp[i][j-1]
                        diag = dp[i-1][j-1]
                        dp[i][j] = v + top + left - diag
                return dp

            def query(dp, r1, c1, r2, c2):
                full = dp[r2 + 1][c2 + 1]
                top = dp[r1][c2 + 1]
                left = dp[r2 + 1][c1]
                sub = dp[r1][c1]
                return full - top - left + sub

            obs = build(grid)
            pre = [[0] * (N+1) for _ in range(M+1)]
            for i in range(M - h + 1):
                for j in range(N - w + 1):
                    q = query(obs, i, j, i + h-1, j + w-1)
                    if q != 0: continue
                    pre[i][j] += 1
                    pre[i + h][j + w] += 1
                    pre[i][j + w] -= 1
                    pre[i + h][j] -= 1
            ans = build(pre)
            for i in range(1, M + 1):
                for j in range(1, N + 1):
                    if grid[i - 1][j - 1] == 0:
                        if ans[i][j] == 0:
                            return False
            return True
