class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        vowels = {"a", "e", "i", "o", "u"}
        ans = 0
        N = len(word)
        def valid(s):
            a = {}
            for ch in s:
                if ch not in vowels:
                    return False
                a[ch] = 1
            return len(a) == 5

        for i in range(N):
            for j in range(i+5, N+1):
                if valid(word[i:j]):
                    ans += 1
        return ans
