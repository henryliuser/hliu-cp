class Solution:
    def longestDupSubstring(self, s: str) -> str:
        ans = -1
        N = len(s)
        MOD = (1 << 99) - 115
        def rabin_karp(src, m, b, q) -> int:
            # returns index of str length m
            # otherwise returns -1
            h, d, t = pow(2, b*m-b, q), 1 << b, 0
            for i in range(m):
                t = (d * t + src[i]) % q
            hashes = {t}
            for i in range(m, len(src)):
                t = (d * (t-src[i-m]*h) + src[i]) % q
                if t in hashes:
                    return i-m+1
                hashes.add(t)
            return -1

        lo, hi = 0, N
        asciis = [ord(ch) - ord('a') for ch in s]
        while lo < hi:
            mid = ceil((lo+hi) / 2)
            rk = rabin_karp(asciis, mid, 5, MOD)
            if rk == -1:
                hi = mid-1
            else:
                ans = rk
                lo = mid

        return "" if ans == -1 else s[ans:ans+lo]
