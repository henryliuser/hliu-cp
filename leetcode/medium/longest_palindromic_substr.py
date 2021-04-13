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

        # O(N^3) brute force, TLE
        def memo(f):
            inp = {}
            def helper(x):
                if not x in inp:
                    inp[x] = f(x)
                return inp[x]
            return helper

        @memo
        def isPal(st):
            for i in range(len(st)//2):
                if st[i] != st[-i-1]: return False
            return True

        ls = len(s)
        ans = ""
        for i in range(ls):
            curr = ""
            for char in s[i:]:
                curr += char
                if isPal(curr) and (len(curr) > len(ans)):
                    ans = curr
        if not ans: return s[0]
        return ans

        # Manacher's Algorithm O(N)
        # NOT MY SOLUTION
        #
        # Transform S into T.
        # For example, S = "abba", T = "^#a#b#b#a#$".
        # ^ and $ signs are sentinels appended to each end to avoid bounds checking
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
