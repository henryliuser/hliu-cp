from collections import defaultdict

ans = 0
N = int(input())
dp = defaultdict(int)
dp["polycarp"] = 1
for _ in range(N):
    a, _, b = (s.lower() for s in input().split())
    dp[a] = 1 + dp[b]
    ans = max(ans, dp[a])

print(ans)
