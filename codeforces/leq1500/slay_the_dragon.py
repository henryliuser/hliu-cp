import sys
from bisect import bisect_left
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    x, y = intput()
    i = bisect_left(A, x)
    if i == N: i -= 1
    send, keep = A[i], s-A[i]
    L = max(0, x-send) + max(0, y-keep)
    if i == 0: return L
    send, keep = A[i-1], s-A[i-1]
    R = max(0, x-send) + max(0, y-keep)
    return min(L, R)

if __name__ == '__main__':
    N, = intput()
    A = sorted(intput())
    s = sum(A)
    M, = intput()
    for _ in range(M):
        print( solve() )
