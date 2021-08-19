MOD = (1 << 99) - 115
mp  = {'A': 1, 'C': 2, 'G': 3, 'T': 4}

def rabin_karp(s, m, b, q, hashes, comp=None):
    h, d, t = pow(2, b*m-b, q), 2**b, 0
    for i in range(m):
        t = (d * t + s[i]) % q
    hashes[0].add(t)
    if comp and t in comp[0]: return
    for i in range(m, len(s)):
        t = (d * (t-s[i-m]*h) + s[i]) % q
        hashes[i-m+1].add(t)
        if comp and t in comp[i-m+1]: return
    # if comp != None:
    #     print('-'*20)
    #     for i in range(len(hashes)): print(hashes[i], comp[i])
    #     print('-'*20)

def check(g) -> bool:
    srk = [set() for _ in range(M-g+1)]
    prk = [set() for _ in range(M-g+1)]
    for s in spots: rabin_karp(s, g, 5, MOD, srk)
    for p in plain: rabin_karp(p, g, 5, MOD, prk)
    for a, b in zip(srk, prk):
        if len(a & b) == 0:
            return True
    return False


    return False
    # print(srk)
    # print(prk)
    # for a, b in zip(srk, prk):
    #     if len(a & b) == 0:
    #         return True
    # return False

if __name__ == '__main__':
    # import sys
    # sys.stdin  = open('cownomics.in', 'r')
    # sys.stdout = open('cownomics.out', 'w')
    N, M = map(int, input().split())
    spots = [[mp[ch] for ch in input()] for _ in range(N)]
    plain = [[mp[ch] for ch in input()] for _ in range(N)]

    lo, hi = 0, M
    while lo < hi:
        mid = (lo + hi) // 2
        print()
        print(lo,hi,mid)
        if check(mid): hi = mid
        else: lo = mid + 1
    print(lo)
