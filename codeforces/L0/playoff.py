# https://codeforces.com/contest/1651/problem/A
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    return pow(2,N) - 1

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
