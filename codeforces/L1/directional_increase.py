# https://codeforces.com/contest/1694/problem/C
import sys
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
from random import randint as rng

def solve(N, A):
    cur = 0
    for i in range(N):
        cur += A[i]
        if cur < 0: return "No"
    if cur != 0: return "No"

    for j in range(N-1, -1, -1):
        if A[j] != 0: break

    cur = 0
    B = [0] * N
    for i in range(j-1): B[i] = 1  # advance
    for i in range(j-1, -1, -1):
        y = A[i+1]
        x = B[i+1]
        d = x - y
        B[i+1] -= d
        B[i] += d
        if i: B[i] -= 1
        if B[i] < A[i]: return "No"
    return "Yes" if A == B else "No"

def test():
    N = rng(5,10)
    Q = rng(4,50)
    i = 0
    A = [0] * N
    record = []
    def R():
        nonlocal i, A, record
        A[i] += 1
        i += 1
        record += ['R']
    def L():
        nonlocal i, A, record
        A[i] -= 1
        i -= 1
        record += ['L']

    for _ in range(Q):
        if i == 0:     R()
        elif i == N-1: L()
        elif rng(0,1): R()
        else:          L()
    while i: L()

    print(A)
    # print(record)
    # print()
    return N, A

if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        N, = intput()
        A = [*intput()]
        print( solve(N,A) )

    # for i in range(20):
    #     N, A = test()
    #     print( solve(N,A) )

"""
1
4
1 -1 1 -1
"""
