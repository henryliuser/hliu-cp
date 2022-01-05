import sys
from bisect import bisect_left
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def factors(x):
    f = set()
    for i in range(1, x+1):
        if i*i > x: break
        if x % i: continue
        f.add(x // i)
        f.add(i)
    return f

def prime_factors(x):
    if x <= 1: return set()
    for i in range(2, int(x**.5)+1):
        if x % i == 0:
            return prime_factors(x//i) | {i}
    return {x}

def solve():
    N, M = intput()
    sfn = [0] + sorted(factors(N))
    pfm = prime_factors(M)

    K, P = len(sfn), len(pfm)
    i = bisect_left(sfn, P)
    if i == K: i -= 1
    if sfn[i] > P: i -= 1
    return sfn[i]

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
