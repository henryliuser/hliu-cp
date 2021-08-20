class Solution:
    def longestPrefix(self, s: str) -> str:
        N, Q, D = len(s), int(1e9+7), 2**5
        if N == 1: return ""
        pd = [1]
        for _ in range(N):  # precompute mod powers of D
            pd.append((pd[-1] * D) % Q)

        def rabin_karp(src):
            t, hashes = 0, []
            for i in range(len(src)):
                t = (D * t + ord(src[i])) % Q
                hashes.append(t)
            return hashes

        pre_hashes = rabin_karp(s)
        suf_hashes = [pre_hashes[-1]]
        for i in range(N-1):
            last = suf_hashes[-1]
            last = (last - ord(s[i]) * pd[N-i-1]) % Q
            # ^ compute suffix polynomial hash
            suf_hashes.append(last)

        for i in range(N-2, -1, -1):
            if pre_hashes[i] == suf_hashes[~i]:
                return s[~i:]

        return ""
