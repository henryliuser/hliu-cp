N = int(input())
MOD = int(1e9 + 7)
dp = [0] * (N+1)
dp[0:3] = 1, 1, 2
for x in range(3,N+1):
    for roll in range(1, 7):
        if x >= roll:
            dp[x] += dp[x-roll]
            dp[x] %= MOD
        else: break
print(dp[N] % MOD)
