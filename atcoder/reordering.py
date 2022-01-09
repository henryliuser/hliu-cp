# no idea how this is TLE.
import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
MXN = 5001
MOD = 998244353

fact, minv, finv = [1]*MXN, [1]*MXN, [1]*MXN
for i in range(2, MXN):
    fact[i] = i * fact[i - 1] % MOD
    minv[i] = MOD-MOD//i*minv[MOD%i]%MOD
    finv[i] = finv[i-1] * minv[i] % MOD

def nCr(n, r):
    v = fact[n] * finv[r] % MOD
    return v * finv[n-r] % MOD

if __name__ == '__main__':
    S = input()
    cnt = defaultdict(int)
    for ch in S: cnt[ch] += 1

    T = sorted(cnt)
    N, C = len(S), len(T)
    dp = [[0]*(N+1) for _ in range(C)]

    for i in range(C):
        dp[i][0] = 1
        c = cnt[T[i]]
        for sz in range(1, N+1):
            if i == 0 and c >= sz:
                dp[i][sz] = 1
                continue
            for j in range(min(sz, c)+1):
                v = (nCr(sz, j) * dp[i-1][sz-j]) % MOD
                dp[i][sz] = (dp[i][sz] + v) % MOD

    ans = -1
    for x in dp[-1]:
        ans = (ans + x) % MOD
    print(ans)
