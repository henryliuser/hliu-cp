class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        ans = set()
        MOD = int(1e9+7)
        N = len(text)
        def rabin_karp(src:list, m:int, b:int, q:int) -> set:
            h, d, t = pow(2, b*m-b, q), 2**b, 0
            for i in range(m):
                t = (d * t + src[i]) % q
            hashes = [t]
            for i in range(m, len(src)):
                t = (d*(t-src[i-m]*h) + src[i]) % q
                if len(hashes) >= m and t == hashes[-m]:
                    ans.add(text[i-m+1:i+1])
                    hashes.append(-1)
                else: hashes.append(t)

        asc = [ord(ch) - ord('a') for ch in text]
        for length in range(1, N+1):
            rabin_karp(asc, length, 5, MOD)
        return len(ans)
    
