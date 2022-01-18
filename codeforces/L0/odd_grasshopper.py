# https://codeforces.com/problemset/problem/1607/B
# brute force the pattern
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    x, n = intput()
    cyc = n % 4
    if cyc == 0: dx = 0
    if cyc == 1: dx = n
    if cyc == 2: dx = 1
    if cyc == 3: dx = n+1
    if x % 2: dx *= -1
    return x + dx

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
