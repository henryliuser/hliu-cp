N, X = map(int, input().split())
price = list(map(int, input().split()))
pages = list(map(int, input().split()))

ans = 0
dp = [[0] * (X+1) for _ in range(2)]
for r in range(1, N+1):
    w = price[r-1]
    p = pages[r-1]
    t = r % 2
    for c in range(1, X+1):
        dp[t][c] = dp[not t][c]
        if c >= w:
            dp[t][c] = max(dp[t][c], p + dp[not t][c-w])

print(dp[N%2][-1])
