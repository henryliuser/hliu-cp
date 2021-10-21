# tle cuz python slow
import sys
from collections import defaultdict
intput = lambda : map(int, input().split())

MOD = int(1e9+7)

if __name__ == '__main__':
    sys.stdin  = open('poetry.in',  'r')
    sys.stdout = open('poetry.out', 'w')
    N, M, K = intput()
    count = defaultdict(int)
    lines = defaultdict(int)
    words = [tuple(intput()) for _ in range(N)]
    dp = [1] + [0] * K
    for i in range(1,K+1):
        for syl, rhy in words:
            if syl > i: continue
            dp[i] += dp[i-syl]
            if i == K:
                count[rhy] += dp[i-syl]

    for i in range(M):
        lines[input()] += 1

    ans = 1
    for ch in lines:
        rep = lines[ch]
        cur = 0
        for rhy in count:
            cur += pow(count[rhy], rep, MOD)
            cur %= MOD
        ans = (ans * cur) % MOD
    print(ans)
