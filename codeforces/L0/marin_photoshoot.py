# https://codeforces.com/contest/1658/problem/A
import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
enum   = enumerate
dfd    = defaultdict

def solve():
    ans = 0
    N, = intput()
    S = input()
    A = [ S[0] ]

    for i in range(1, N):
        ch = S[i]
        if ch == A[-1] == '0':
            A += ['1', '1']
            ans += 2
        elif len(A) >= 2 and ch == '0' and A[-2:] == ['0', '1']:
            A += ['1']
            ans += 1
        A += [ch]
    # print(''.join(A))
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
