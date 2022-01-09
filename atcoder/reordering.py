import sys
from functools import lru_cache
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
MXN = 5001
MOD = 998244353

fact = [1] * MXN
for i in range(1, MXN):
    fact[i] = i * fact[i-1] % MOD

def modPow(a, b, m):
    a %= m
    res = 1
    while b:
        if b&1: res = res * a % m
        a = a*a % m
        b = b >> 1
    return res

inv = lambda  x  : modPow(x, MOD-2, MOD)
div = lambda a,b : a * inv(b) % MOD
def nCr(n, r):
    v = (fact[r] * fact[n-r]) % MOD
    return div(fact[n], v)

@lru_cache(None)
def dfs(i, x):  # of seq length x, using alphabet T[i:]
    if x == 0: return 1
    if i >= C: return 0
    # if dp[i][x] != -1:
    #     return dp[i][x]
    res = 0
    c = cnt[T[i]]
    for j in range(c, -1, -1):
        v = nCr(x, j)
        res += v * dfs(i+1, c-j)
    # dp[i][x] = res
    return res

if __name__ == '__main__':
    S = input()
    cnt = defaultdict(int)
    for ch in S: cnt[ch] += 1

    N, C = len(S), len(cnt)
    T = sorted(cnt)

    ans = 0
    for sz in range(1, N+1):
        ans += dfs(0, sz)
    print(ans)
