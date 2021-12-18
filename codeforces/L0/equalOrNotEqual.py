# https://codeforces.com/problemset/problem/1620/A
import sys
from collections import Counter
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    return "NO" if Counter(input())['N'] == 1 else "YES"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
