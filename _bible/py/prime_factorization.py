def prime_factors(x):
    for i in range(2, int(x**.5)+1):
        if x % i == 0:
            return prime_factors(x//i) | {i}
    return {x}

def prime_factors(x, spf):
    factors = set()
    while x != 1:
        factors.add(spf[x])
        x /= spf[x]
    return factors
