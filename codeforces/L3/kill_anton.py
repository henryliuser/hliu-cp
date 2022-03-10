# https://codeforces.com/contest/1526/problem/D
# hope u get the intuition that they can be contiguous
# then count inversions per char against other chars
# then take the best permutation of 'ANTO'
import sys
from itertools import *
from collections import *
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
dfd = defaultdict
enum = enumerate

A = "ANTO"
def solve():
    S = input()
    cnt = dfd(int)
    inv = dfd(lambda : dfd(int))
    for ch in S:
        for c in A:
            inv[c][ch] += cnt[c]
        cnt[ch] += 1

    ans = -1
    best = []
    for p in permutations(A):
        res = 0
        for i in range(4):
            for j in range(i+1,4):
                x = inv[ p[j] ][ p[i] ]
                res += x

        if res > ans:
            ans = res
            best = p

    a,n,t,o = best
    return f"{a*cnt[a]}{n*cnt[n]}{t*cnt[t]}{o*cnt[o]}"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
