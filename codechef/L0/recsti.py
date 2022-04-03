import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
enum   = enumerate
dfd    = defaultdict

def solve():
    N, = intput()
    A = Counter( intput() )
    ans = t = 0
    for x,c in A.items():
        ans += c % 2
        t += c + c % 2
    return ans + t%4

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
