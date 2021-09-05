# generate all primes in range [1:N] in O(N log log N)
from math import sqrt

def sieve(N):
    primes = [True] * (N+1)
    primes[0] = primes[1] = False
    for i in range(2, int(sqrt(N))+1):
        if i*i > N: break
        if primes[i]:
            for j in range(i*i, N+1, i):
                primes[j] = False
    return [i for i,p in enumerate(primes) if p]
