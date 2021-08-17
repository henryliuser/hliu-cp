def rabin_karp(src:list, m:int, b:int, q:int) -> list:
    # return list of hashes length m with base b, module q
    h, d, t = (1<<(b*m-b))%q, 1 << b, 0
    for i in range(m):
        t = (d * t + src[i]) % q
    hashes = [t]
    for i in range(len(src) - m):
        t = (d*(t-src[i]*h) + src[i + m]) % q
        hashes.append(t)
    return hashes
