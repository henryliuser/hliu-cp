# https://atcoder.jp/contests/arc132/tasks/arc132_b
# investigate by generating cases logically and looking for patterns
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def check(L):
    for i in range(1, len(L)):
        if abs(L[i] - L[i-1]) != 1:
            return i
    return -1 if L[-1] > L[-2] else -2

def solve(N, A):
    i = check(A)
    if i == -1: return 0
    if i == -2: return 1
    if A[i] > A[i-1]: i += 1
    R = A[::-1]
    j = check(R)
    if R[j] > R[j-1]: j += 1
    return min(i, j+1)

if __name__ == '__main__':
    N, = intput()
    A = list(intput())
    print( solve(N, A) )

    # problem investigation
    # from random import randint as rng
    # from collections import deque
    # def rand():
    #     dq = deque(range(1, rng(5,12)))
    #     for i in range(rng(50,100)):
    #         if rng(0,1):
    #             dq.append( dq.popleft() )
    #         else:
    #             dq.reverse()
    #     return list(dq)
    #
    # for _ in range(10):
    #     print(rand())
