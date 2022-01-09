import sys
from math import sqrt
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    for i in range(N):
        print(i+2)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        solve()
