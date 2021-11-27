# https://codeforces.com/contest/1589/problem/A
import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    u, v = intput()
    print(-u*u, v*v)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        solve()
