import sys
from collections import Counter
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = list(intput())
    B, last = [], None
    while 1:
        if A == last: break
        last = A[:]
        B += [ A[:] ]
        c = Counter(A)
        for i,x in enumerate(A):
            A[i] = c[x]

    z = len(B)-1
    Q, = intput()
    for _ in range(Q):
        x, k = intput()
        print(B[min(k,z)][x-1])

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        solve()
