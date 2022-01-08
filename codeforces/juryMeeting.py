import sys
from collections import Counter
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
MXN = int(2e5+2)
MOD = 998244353

fact = [1] * MXN
for i in range(1, MXN):
    fact[i] = (i * fact[i-1]) % MOD

def nPr()

def solve():
    N, = intput()
    C  = Counter(intput())
    A  = sorted(C, reverse=True)

    if len(A) == 1: return fact[N]
    if C[ A[0] ] == 1 and A[0] - A[1] > 1:
        return 0

    q, r = C[A[0]], C[A[1]]
    left = N - q - r
    ans = 0
    # ans = ( (N-1) * y * fact[N-2] ) % MOD
    # ans = (ans + q * (q-1) * 2) % MOD
    f = fact[left]
    for i in range(left):
        g = N - i
        # permute g in (q+r) spots
        N - i


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
