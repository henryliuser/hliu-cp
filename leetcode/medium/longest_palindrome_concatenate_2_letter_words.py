class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ans = 0
        s = Counter(words)
        def upd(x):
            s[x] -= 1
            if s[x] == 0: del s[x]
        for w in words:
            if w not in s: continue
            rev = w[::-1]
            if (w == rev and s[w] > 1) or (w != rev and rev in s):
                ans += 4
                upd(w), upd(rev)
        for w in s:
            if w == w[::-1]:
                ans += 2
                break
        return ans
