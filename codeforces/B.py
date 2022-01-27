import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = list(intput())[::-1]
    if len(set(A)) == 1: return 0

    ans = 0
    i = st = 1
    while i < N:
        if A[i] == A[0]:
            st += 1
        else:
            ans += 1
            for j in range(st):
                if i+j < N:
                    A[i+j] = A[0]
                    st += 1
                else: break
            i += j
        i += 1
    return ans


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
