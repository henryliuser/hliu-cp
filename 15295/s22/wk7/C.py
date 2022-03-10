# https://codeforces.com/problemset/problem/1195/D2
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
Q = 998244353

qsum = lambda x,y : (x+y)%Q
qmul = lambda x,y : (x*y)%Q

def f(A, x):
    res, p = 0, 1
    for i in range( max(len(A),x) ):
        if i < x:
            p = qmul(p, 10)
        if i < len(A):
            res = qsum(res, qmul(A[i], p))
            p = qmul(p, 10)
    return res

def g(x, B):
    res, p = 0, 1
    for i in range( max(x,len(B)) ):
        if i < len(B):
            res = qsum(res, qmul(B[i], p))
            p = qmul(p, 10)
        if i < x:
            p = qmul(p, 10)
    return res

if __name__ == '__main__':
    N, = intput()
    A = [*intput()]
    L = [0] * 11
    for x in A:
        n = len( str(x) )
        L[n] += 1

    ans = 0
    for i in range(N):
        dig = [*map(int, str(A[i]))][::-1]
        for x in range(1, 11):
            s = f(dig, x)
            ans = qsum(ans, qmul(s, L[x]))
            s = g(x, dig)
            ans = qsum(ans, qmul(s, L[x]))

    print(ans)
