class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        ans = set()
        MOD = (1 << 99) - 115
        if len(s) < 10: return []
        def rabin_karp(src, m, b, q):
            h, d, t = pow(2, b*m-b, q), 2**b, 0
            for i in range(m):
                t = (d*t + src[i]) % q
            hashes = {t}
            for i in range(m, len(src)):
                t = (d*(t-src[i-m]*h) + src[i]) % q
                if t in hashes:
                    idx = i-m+1
                    ans.add(s[idx:idx+m])
                else: hashes.add(t)
        asciis = [ord(ch) - ord('a') for ch in s]
        rabin_karp(asciis, 10, 3, MOD)
        return list(ans)
