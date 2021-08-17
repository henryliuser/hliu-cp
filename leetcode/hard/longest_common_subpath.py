class Solution:
    def longestCommonSubpath(self, n: int, paths: List[List[int]]) -> int:
        MOD = (1 << 99) - 115  # must be >>>>>> N^2 for comparing N strings
        BASE = 17  # choose such that 2^b > A for alphabet size A

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

        ans = 0
        M = len(paths)
        source = min(paths, key=lambda x: len(x))
        lo, hi = 0, len(source)
        while lo < hi:
            mid = ceil((lo + hi) / 2)
            all_hashes = [set(rabin_karp(p, mid, BASE, MOD)) for p in paths]
            inter = set.intersection(*all_hashes)
            if len(inter) > 0:
                ans = lo = mid
            else:
                hi = mid-1
        return ans
        
