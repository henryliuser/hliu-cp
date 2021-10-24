class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        for i in range(n+1, 1666666):
            c = Counter(str(i))
            for dig in c:
                if int(dig) != c[dig]:
                    break
            else:
                return i
