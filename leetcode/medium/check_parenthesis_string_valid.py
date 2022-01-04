class Solution:
    def canBeValid(self, s: str, lock: str) -> bool:
        N = len(s)
        if N % 2: return False
        def ok(loop, ch):
            bal = free = 0
            for i in loop:
                if lock[i] == '1':
                    bal += 1 if s[i] == ch else -1
                if lock[i] == '0':
                    free += 1
                if free + bal < 0:   # invariant of valid str
                    return False
            return abs(bal) <= free  # total must be covered

        r1, r2 = range(N), range(N-1, -1, -1)
        return ok(r1, '(') and ok(r2, ')')
