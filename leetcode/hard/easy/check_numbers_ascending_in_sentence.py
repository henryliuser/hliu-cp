class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        last = 0
        for tk in s.split():
            try:
                x = int(tk)
                if x <= last: return False
                last = x
            except:
                continue
        return True
