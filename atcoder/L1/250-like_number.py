# https://atcoder.jp/contests/abc250/tasks/abc250_d 
import sys
input = lambda: sys.stdin.readline().strip()
intput = lambda: map(int, input().split())

def sieve(N):
    y = int(N ** .5) + 1
    spf = [0] * (N + 1)
    spf[0] = spf[1] = -1
    for i in range(3, N + 1, 2): spf[i] = i
    for i in range(2, N + 1, 2): spf[i] = 2
    for i in range(3, y, 2):
        if spf[i] != i: continue
        for j in range(i * i, N + 1, i):
            if spf[j] == j:
                spf[j] = i
    return spf


if __name__ == '__main__':
    N, = intput()
    M = int(N ** (1 / 3))
    spf = sieve(M+1)

    #  [ (# of primes < i), (largest prime < i) ]
    cnt = [ [0,0] for _ in range(M+1) ]
    for i in range(1, M+1):
        c,m = cnt[i-1]
        if spf[i] == i:
            c, m = c+1, i
        cnt[i] = [c,m]

    ans = 0
    for q in range(M+1):
        qc = q*q*q
        if qc > N: break
        if spf[q] != q: continue
        l,r,a = 0, q-1, (0,0)
        while l < r:
            m = (l+r+1) // 2
            c,p = cnt[m]
            if p * qc > N:
                r = m-1
            else:
                a = c,p
                l = m
        ans += a[0]
    print(ans)
