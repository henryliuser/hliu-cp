import sys
from functools import lru_cache
intput = lambda : map(int, input().split())

def solve():
    ans = 0
    N = int(input())
    A = list(intput())

    dp = {}
    def dfs(i):
        if i >= N: return 0
        if i in dp: return dp[i]
        dp[i] = A[i] + dfs(i + A[i])
        return dp[i]

    for x in range(N):
        ans = max(ans, dfs(x))
    return ans

T = int(input())
for _ in range(T):
    sys.setrecursionlimit(100000)
    print( solve() )
