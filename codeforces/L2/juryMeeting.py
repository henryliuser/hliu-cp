import sys
from collections import Counter
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
MXN = int(2e5+2)
MOD = 998244353

fact = [1] * MXN
for i in range(1, MXN):
    fact[i] = (i * fact[i-1]) % MOD

# using built-in pow is surprisingly 2x slower
def modPow(a, b, m):
    a %= m
    res = 1
    while b:
        if b&1: res = res * a % m
        a = a*a % m
        b = b >> 1
    return res

def modnPr(n, r):
    # fermat's little theorem: if Q prime,
    # modInv(a,Q) = a^(Q-2) % Q
    inv = lambda  a  : modPow(a, MOD-2, MOD)
    div = lambda a,b : a * inv(b) % MOD
    return div(fact[n], fact[n-r])

def solve():
    N, = intput()
    C  = Counter(intput())
    A  = sorted(C, reverse=True)

    if len(A) == 1 or C[ A[0] ] > 1: return fact[N]
    if C[ A[0] ] == 1 and A[0] - A[1] > 1:
        return 0

    q, r = C[A[0]], C[A[1]]
    left = N - q - r
    ans = 0

    f = fact[left]
    for i in range(N-q):
        t = fact[N-1]
        if i >= q+r-1:
            m = modnPr(i, q+r-1)
            v = (m * f) % MOD
            t = (t - v) % MOD
        ans = (ans + q*t) % MOD
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )

# from itertools import permutations
#
# def sim(A, P):
#     N, s = len(A), sum(A)
#     c = 0
#     B = A[:]
#     last = -1
#     while s > 0:
#         p = P[c]
#         c = (c+1) % N
#         if B[p-1] == 0: continue
#         if p == last: return False
#         B[p-1] -= 1
#         s -= 1
#         last = p
#     return True
#
# def test():
#     N, = intput()
#     A  = list(intput())
#     m = max(A)
#     good = []
#     for p in permutations(range(1,N+1)):
#         if sim(A, p):
#             q = [A[i-1] for i in p]
#             good += [q]
#
#     for i in range(N):
#         a = []
#         for g in good:
#             if g[i] == m:
#                 a += [g]
#         print(i, len(a))
#     print('tot:', len(good))
#
#
# test()
