def maxSubsetSum(arr):
    N = len(arr)
    dp = [[0,0] for _ in range(N+1)]
    for x in range(1, N+1):
        a = arr[x-1]
        dp[x][0] = max(dp[x-1])  # don't take
        if a <= 0: dp[x][1] = dp[x][0]
        else:  # take
            dp[x][1] = dp[x-1][0] + a
            if x >= 2: dp[x][1] = max(dp[x][1], dp[x-2][1] + a)
    return max(dp[N])
