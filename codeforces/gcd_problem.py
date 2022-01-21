import sys
from math import gcd
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    for i in range(2,N):
        j = N-i-1
        if gcd(i,j) == 1:
            return i,j,1

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( *solve() )
