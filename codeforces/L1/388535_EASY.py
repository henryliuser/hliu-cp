# https://codeforces.com/contest/1658/problem/D1
# if the parity is off, correct it
import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    ans = 0
    L, R = intput()

    cnt = [0] * 17
    for x in range(R+1):
        for b in range(17):
            cnt[b] += bool(x & (1<<b))

    my = [0] * 17
    for x in intput():
        for b in range(17):
            my[b] += bool(x & (1<<b))

    for b in range(17):
        if my[b] != cnt[b]:
            ans |= (1 << b)

    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
