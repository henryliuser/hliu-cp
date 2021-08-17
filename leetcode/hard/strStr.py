class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        MOD = (1 << 32) - 5
        BX = 5
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

        M, N = len(needle), len(haystack)
        if not M: return 0
        if not N or M > N: return -1
        hvals = [ord(x)-ord('a') for x in haystack]
        nvals = [ord(x)-ord('a') for x in needle]
        d,t = 1 << BX, 0
        for i in range(M):
            t = (d*t + nvals[i]) % MOD

        rk = rabin_karp(hvals, M, BX, MOD)
        for i,h in enumerate(rk):
            if h == t: return i
        return -1
            
