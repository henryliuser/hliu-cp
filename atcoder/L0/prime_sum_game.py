# https://atcoder.jp/contests/abc239/tasks/abc239_d
import sys
from bisect import bisect_left
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def sieve(N):
    y = int(N**.5) + 1
    spf = [0] * (N+1)
    spf[0] = spf[1] = -1
    for i in range(3, N+1, 2): spf[i] = i
    for i in range(2, N+1, 2): spf[i] = 2
    for i in range(3, y, 2):
        if spf[i] != i: continue
        for j in range(i*i, N+1, i):
            if spf[j] == j:
                spf[j] = i
    return spf

def solve():
    spf = sieve(205)
    A,B,C,D = intput()
    for tk in range(A, B+1):
        for ak in range(C, D+1):
            x = tk+ak
            if spf[x] == x: break
        else: return "Takahashi"
    return "Aoki"

if __name__ == '__main__':
    print( solve() )
