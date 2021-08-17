# q must be significantly greater than N^2 for comparing N strings
# 2^b must be greater than A for alphabet size A

# N = 100,000  |  q = (1 << 99) - 115
# A = 100,000  |  b = 17

# N = 2  |  q = (1 << 10) - 3
# A = 26 |  b = 5

def rabin_karp(src:list, m:int, b:int, q:int) -> set:
    # return set of hashes length m with base 2^b, module q
    h, d, t = pow(2, b*m-b, q), 2**b, 0
    for i in range(m):
        t = (d * t + src[i]) % q
    hashes = {t}
    for i in range(m, len(src)):
        t = (d*(t-src[i-m]*h) + src[i]) % q
        hashes.add(t)
    return hashes
