class Solution:
    def countValidWords(self, sentence: str) -> int:
        puncs = {' ', '!', '.', ','}
        def isValid(s):
            puncI = -1
            hyphI = -1
            if s in puncs: return True
            for i,ch in enumerate(s):
                if ord('0') <= ord(ch) <= ord('9'): return False
                if ch in puncs:
                    if puncI != -1: return False
                    if i != len(s)-1: return False
                    puncI = i
                if ch == '-':
                    if hyphI != -1: return False
                    if i == 0 or i == len(s) -1: return False
                    if not s[i-1].isalpha() or not s[i+1].isalpha(): return False
                    hyphI = i
            return True
        return sum(1 for s in sentence.split() if isValid(s))

                    
