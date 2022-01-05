# https://codeforces.com/contest/1621/problem/C
# cool problem.
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def query(i):
    print('?', i)
    sys.stdout.flush()
    x, = intput()
    return x

def submit(A):
    print('!', *A)
    sys.stdout.flush()

def solve():
    s = set()
    N, = intput()
    ans = [-1] * N
    for i in range(N):
        if ans[i] != -1: continue
        prev = -1
        while 1:
            x = query(i+1)
            if prev != -1:
                ans[prev-1] = x
            if x in s: break
            s.add(x)
            prev = x
    submit(ans)

if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        solve()

# def permute(A, P):
#     return [A[x-1] for x in P]
#
# def test():
#     from itertools import permutations
#     from random import randint as rng
#     N = 7
#     Q = list(range(1,N+1))
#     allP = list(permutations(Q))
#     f = len(allP)
#     P = allP[ rng(0,f-1) ]
#     for _ in range(N+2):
#         print(Q)
#         Q = permute(Q, P)
#
# test()
