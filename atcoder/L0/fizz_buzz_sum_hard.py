# https://atcoder.jp/contests/abc253/tasks/abc253_d
# wa cuz of bad formula during contest?
import sys
from math import gcd
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(N,A,B):
    L = A * B // gcd(A,B)
    def s(z):
        n = N // z
        return n * (n+1) // 2 * z
    d = s(A) + s(B) - s(L)
    return N * (N+1) // 2 - d

if __name__ == '__main__':
    N,A,B = intput()
    print( solve(N,A,B) )

    # from random import randint as rng
    # def test(N,A,B):
    #     ans = 0
    #     for i in range(1,N+1):
    #         if i % A == 0 or i % B == 0: continue
    #         ans += i
    #     return ans
    # print( solve(1000000000, 3, 1000000000) )
    # print( solve(1000000000, 3, 3) )
    # print( solve(10, 10, 10) )
    # for _ in range(100000):
    #     N = rng(1, 10000)
    #     A = rng(1, 10000)
    #     B = rng(1, 10000)
    #     t = test(N,A,B)
    #     s = solve(N,A,B)
    #     if t != s:
    #         print(N,A,B)
    #         print(t,s)
    #         print()
