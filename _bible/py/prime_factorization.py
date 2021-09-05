def prime_factors(x):
    for i in range(2, int(math.sqrt(x))+1):
        if x % i == 0:
            return prime_factors(x//i) | {i}
    return {x}
