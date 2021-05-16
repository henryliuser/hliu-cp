class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if not word: return True
        N = len(word)
        count = [0,0]
        for c in word:
            if c.isupper(): count[1] += 1
            else: count[0] += 1
        if count[1] == N: return True
        if count[0] == N: return True
        if word[0].isupper() and count[1] == 1: return True
        return False
                
