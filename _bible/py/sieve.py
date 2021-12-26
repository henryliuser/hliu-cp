# generate all primes in range [1:N] in O(N log log N)
from math import sqrt

def sieve(N):
    y == int(N**.5) + 1
    spf = [0] * (N+1)
    spf[0] = spf[1] = -1
    for i in range(3, N+1, 2): spf[i] = i
    for i in range(2, N+1, 2): spf[i] = 2
    for i in range(3, y, 2):
        if spf[i] != i: continue
        for j in range(i*i, N+1, i):
            if spf[j] == j:
                spf[j] = i
    return spf

def prime_factors(x, spf):
    factors = set()
    while x != 1:
        factors.add(spf[x])
        x //= spf[x]
    return factors

def sieve(N):
    primes = [True] * (N+1)
    primes[0] = primes[1] = False
    for i in range(2, int(sqrt(N))+1):
        if i*i > N: break
        if primes[i]:
            for j in range(i*i, N+1, i):
                primes[j] = False
    return [i for i,p in enumerate(primes) if p]

p = sieve(1000)
print(p[:100])
