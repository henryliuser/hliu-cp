# https://leetcode.com/problems/construct-string-with-repeat-limit/
# shitty solution, whatever
class Solution:
    def repeatLimitedString(self, s: str, lim: int) -> str:
        N = len(s)
        c = Counter(s)
        bank = sorted(c, reverse=True)
        B = len(bank)

        def hasBetter(j):
            for q in range(j):
                if c[bank[q]] > 0:
                    return q
            return -1

        j = 0
        ans = []
        while j < len(bank):
            x = bank[j]
            if c[x] == 0:
                j += 1
                continue
            m = min(c[x], lim)
            k = hasBetter(j)
            if k != -1: m = 1
            ans += [x]*m
            c[x] -= m
            if k != -1: j = k
            else: j += 1

        return ''.join(ans)
