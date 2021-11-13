class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        c1, c2 = defaultdict(int), defaultdict(int)
        for ch in word1: c1[ch] += 1
        for ch in word2: c2[ch] += 1
        for i in range(ord('a'), ord('z')+1):
            ch = chr(i)
            if abs(c1[ch] - c2[ch]) > 3:
                return False
        return True
            
