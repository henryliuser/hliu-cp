# O(N log N) rabin karp binary search
# NOT monotonic over [0,N], but IS monotonic over evens and odds separately
class Solution:
    def longestPalindrome(self, s: str) -> str:
        N = len(s)
        ans = s[0]

        a = [ord(ch) for ch in s]
        b = list(reversed(a))

        Q, B = int(1e9+7), 8  # module and base for rolling hash
        def rabin_karp(src, m):
            h, d, t = pow(2, B*m-B, Q), 2**B, 0
            for i in range(m):
                t = (d*t + src[i]) % Q
            hashes = [t]
            for i in range(m, len(s)):
                t = (d * (t-src[i-m]*h) + src[i]) % Q
                hashes.append(t)
            return hashes

        def check(guess):  # index of palindrome len guess or -1 if none
            if guess > N: return -1
            rk1 = rabin_karp(a, guess)
            rk2 = rabin_karp(b, guess)
            for i, k in enumerate(rk1):
                if rk2[~i] == k:
                    return i
            return -1

        def binary_search(lo, hi, g):  # upper_bound over [g(lo), g(hi)]
            nonlocal ans
            while lo < hi:
                mid = ceil((lo+hi) / 2.0)
                guess = g(mid)
                c = check(guess)
                if c == -1:
                    hi = mid -1
                else:
                    lo = mid
                    if guess > len(ans):
                        ans = s[c: c+guess]

        binary_search(0, N//2, lambda x: 2*x)    # search on evens
        binary_search(0, N//2, lambda x: 2*x+1)  # search on odds
        return ans


class Solution:
    def longestPalindrome(self, s: str) -> str:
        # dp, O(N^2) time, barely AC?
        # dp[l][r] true if s[l:r+1] is palindrome
        ls = len(s)
        if not s: return ""
        dp = [[False] * ls for _ in range(ls)]
        for x in range(ls):  # somehow this really does make it faster
            dp[x][x] = True
        ans = (0, 1)
        for l in range(ls-1, -1, -1):
            for r in range(l+1, ls):
                if s[l] == s[r]:
                    if r-l == 1 or dp[l+1][r-1]:
                        dp[l][r] = True
                        if r-l+1 > ans[1] - ans[0]:
                            ans = (l, r+1)
        return s[ans[0]:ans[1]]



# Manacher's Algorithm O(N)
# NOT MY SOLUTION
#
# Transform S into T.
# For example, S = "abba", T = "^#a#b#b#a#$".
# ^ and $ signs are sentinels appended to each end to avoid bounds checking
class Solution:
    def longestPalindrome(self, s: str) -> str:
        T = '#'.join('^{}$'.format(s))
        n = len(T)
        P = [0] * n
        C = R = 0
        for i in range (1, n-1):
            P[i] = (R > i) and min(R - i, P[2*C - i]) # equals to i' = C - (i-C)
            # Attempt to expand palindrome centered at i
            while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                P[i] += 1

            # If palindrome centered at i expand past R,
            # adjust center based on expanded palindrome.
            if i + P[i] > R:
                C, R = i, i + P[i]

        # Find the maximum element in P.
        maxLen, centerIndex = max((n, i) for i, n in enumerate(P))
        return s[(centerIndex  - maxLen)//2: (centerIndex  + maxLen)//2]
