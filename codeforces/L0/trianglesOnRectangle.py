# https://codeforces.com/problemset/problem/1620/B
import sys
from bisect import bisect_left
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def maxDim(L):
    res = [float('inf'), -1]
    for x in L:
        res[0] = min(res[0], x)
        res[1] = max(res[1], x)
    return res[1] - res[0]

def solve():
    ans = 0
    w, h = intput()
    h1 = list(intput())[1:]  # bottom
    h2 = list(intput())[1:]  # top
    v1 = list(intput())[1:]  # left
    v2 = list(intput())[1:]  # right
    ans = max(ans, maxDim(h1) * h)
    ans = max(ans, maxDim(h2) * h)
    ans = max(ans, maxDim(v1) * w)
    ans = max(ans, maxDim(v2) * w)
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
