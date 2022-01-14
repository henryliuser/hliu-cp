# https://codeforces.com/contest/1554/problem/D
# idek. read the editorial, shit's wild
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    n, = intput()
    k = n//2
    if n == 1: return 'z'
    if n % 2: return 'a'*k + 'bc' + 'a'*(k-1)
    return 'a'*k + 'b' + 'a'*(k-1)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
