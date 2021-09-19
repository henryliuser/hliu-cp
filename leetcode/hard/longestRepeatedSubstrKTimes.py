
class Solution:
    def longestSubstrRepeatedK(self, s: str, k: int) -> str:
        N = len(s)
        B, Q = 5, int(1e9) + 7
        def rabin_karp(src:list, m:int, b:int, q:int) -> set:
            # return set of hashes length m with base 2^b, module q
            toStr = {}
            hashes = defaultdict(int)
            h, d, t = pow(2, b*m-b, q), 2**b, 0
            for i in range(m):
                t = (d * t + src[i]) % q
            hashes[t] += 1
            toStr[t] = 0
            for i in range(m, len(src)):
                t = (d*(t-src[i-m]*h) + src[i]) % q
                hashes[t] += 1
                if not t in toStr: toStr[t] = i
            print(m, hashes)
            print(toStr)
            return [h for h in hashes if hashes[h] == k], toStr

        ans = ""
        asciis = [ord(ch)-ord('a') for ch in s]
        for mid in range(1, N//k):
            hashes, toStr = rabin_karp(asciis, mid, B, Q)
            for h in hashes:
                idx = toStr[h]
                st = s[idx:idx+mid]
                if st > ans: ans = st

        return ans
