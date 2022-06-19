# https://codeforces.com/contest/1694/problem/B
import sys
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    S = input()

    ans = N
    for i in range(1, N):
        if S[i-1:i+1] not in ['00', '11']:
            ans += i
    return ans

if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        print( solve() )
