import sys
from decimal import Decimal, getcontext
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
getcontext().prec = 100
d = Decimal

if __name__ == '__main__':
    T, K = intput()
    T -= 1

    p = [d(1)]
    for _ in range(T):
        pa = [d(0)] + p
        pb = p + [d(0)]
        p = [(x+y)/2 for x, y in zip(pa, pb)]

    E = d(T) / 2  # ev for a single try

    for k in range(1, K):
        nextE = d(0)
        for i in range(T+1):
            nextE += p[i] * max(i,E)
        E = nextE

    getcontext().prec = 20
    print(E+1)
