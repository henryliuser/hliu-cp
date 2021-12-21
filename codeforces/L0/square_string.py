# https://codeforces.com/contest/1619/problem/A
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    s = input()
    N = len(s)
    if N % 2: return "No"
    return "Yes" if s[:N//2] == s[N//2:] else "No"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
