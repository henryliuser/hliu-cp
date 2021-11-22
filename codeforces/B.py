import sys
from bisect import bisect_left
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    ans = []
    N, a, b = intput()
    M = N//2
    if a > M or b <= M:
        return [-1]
    for i in range(M):
        ans.append(N-i)
    for i in range(M):
        ans.append(i+1)
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print(*solve())
