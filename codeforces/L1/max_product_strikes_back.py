# https://codeforces.com/contest/1660/problem/D
# nice question
# max subarray product but be clever about storing the amts
# store as counts of each number and compare logically
import sys
from bisect import *
from collections import *
input = lambda: sys.stdin.readline().rstrip("\r\n")
intput = lambda : map(int, input().split())
enum   = enumerate
dfd    = defaultdict

def cmp(A, B):  # return A > B
    # interpret as count of
    # [0, 1, 2, -2, -1]
    amt = A[2] + A[3]
    bmt = B[2] + B[3]
    aneg = -1 if ( (A[3] + A[4]) % 2 ) else 1
    bneg = -1 if ( (B[3] + B[4]) % 2 ) else 1
    a = aneg * amt
    b = bneg * bmt
    return a > b

def solve():
    N, = intput()
    A = [*intput()]

    ans = [ [0]*5, [0,N] ]

    cur = [0]*5
    l,r = 0, N
    for i,x in enum(A):
        r -= 1
        if x == 0:
            cur = [0]*5
            l = i+1
        else:
            cur[x] += 1
            if cmp(cur, ans[0]):
                ans = [cur[:], [l,r]]

    cur = [0]*5
    l,r = N, 0
    for i,x in enum(reversed(A)):
        l -= 1
        if x == 0:
            cur = [0]*5
            r = i+1
        else:
            cur[x] += 1
            if cmp(cur, ans[0]):
                ans = [cur[:], [l,r]]

    return ans[1]

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( *solve() )
