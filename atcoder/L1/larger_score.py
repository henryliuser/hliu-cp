# https://atcoder.jp/contests/arc138/tasks/arc138_a
import sys
from bisect import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, K = intput()
    A = [*intput()]

    smin = A[:K]
    for i in range(K-2, -1, -1):
        smin[i] = min(smin[i], smin[i+1])

    ans = float('inf')
    for i in range(K, N):
        x = A[i]
        j = bisect_left(smin, x) - 1
        if j < 0: continue
        res = i - j
        ans = min(ans, res)

    return ans if ans != float('inf') else -1

if __name__ == '__main__':
    print( solve() )
