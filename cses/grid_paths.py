N = int(input()) + 1
grid = [[0] * N for _ in range(N)]
dp = [[0] * N for _ in range(N)]
MOD = int(1e9 + 7)

dp[0][1] = 1
for r in range(1, N):
    s = list(input())
    for c in range(1, N):
        if s[c-1] == '*': dp[r][c] = 0
        else: dp[r][c] = (dp[r-1][c] + dp[r][c-1]) % MOD

print(dp[-1][-1] % MOD)
