# https://codeforces.com/contest/1650/problem/A
import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    S = input()
    c = input()
    if c not in S: return "NO"
    for i,ch in enumerate(S):
        if ch != c: continue
        if i % 2 == 0: return "YES"
    return "NO"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
