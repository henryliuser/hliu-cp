import sys
from bisect import bisect_left
input = sys.stdin.readline
intput = lambda : map(int, input().split())


while 3:
    A = list(intput())
    N = len(A)
    B = [0] * N
    for i in range(N):
        for j in range(N):
            B[i] += abs(A[i] - A[j])
    print(sum(set(abs(a) for a in A)))
    print(*sorted(B))

# 3 -3 7 -7 10 -10 30 -30 31 -31
