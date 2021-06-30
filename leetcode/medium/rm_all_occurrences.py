class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        lp = len(part)
        f = s.find(part)
        while f != -1:
            s = s[:f] + s[f+lp:]
            f = s.find(part)
        return s
