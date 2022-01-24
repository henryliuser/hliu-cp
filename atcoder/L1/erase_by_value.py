import sys
from math import inf
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(N, A):
    A += [-inf]
    for i in range(N):
        if A[i] > A[i+1]:
            return [x for x in A[:-1] if x != A[i]]

if __name__ == '__main__':
    N, = intput()
    A  = list(intput())
    print( *solve(N,A) )
