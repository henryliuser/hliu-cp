# https://codeforces.com/contest/1646/problem/C
# really really good question
# expressing a number as distinct powers of 2 is just popcount
# only 2^16 ish relevant factorial subset sums to check
# per test loop all, take min of popcount(N-fac)
import sys
from collections import defaultdict as dfd
input = lambda: sys.stdin.readline().rstrip("\r\n")
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    ans = bin(N)[2:].count('1')
    for s in sums:
        if s > N: break
        x = N-s
        pc = bin(x)[2:].count('1')
        ans = min(ans, pc + dp[s])
    return ans

if __name__ == '__main__':
    fac = [1]
    for i in range(2,16):
        fac += [fac[-1]*i]
    sz = len(fac)
    dp = dfd(lambda : float('inf'))
    for m in range(2**sz):
        s = pc = 0
        for b in range(sz):
            if m & (1<<b):
                s += fac[b]
                pc += 1
        dp[s] = min(dp[s], pc)
    sums = sorted(dp)

    T, = intput()
    for _ in range(T):
        print( solve() )
