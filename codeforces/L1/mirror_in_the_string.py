import sys
from random import randint as rng
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(N, S):
    i = 1
    for i in range(1, N):
        if S[i] == S[i-1] and i == 1: break
        if S[i] > S[i-1]: break
    else: i += 1
    x = S[:i]
    return ''.join(x + x[::-1])

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        N, = intput()
        S  = list(input())
        print( solve(N,S) )


# def check(s):
#     res = []
#     n = len(s)
#     for i in range(1, n+1):
#         x = s[:i]
#         res += [ x + x[::-1] ]
#     res.sort()
#     return ''.join(res[0])
#
# for _ in range(10000):
#     N = rng(1,200)
#     S = [chr(ord('a') + rng(0,25)) for _ in range(N)]
#     c = check(S)
#     s = solve(N,S)
#     if check(S) != solve(N,S):
#         print('mismatch', ''.join(S), c, s)
