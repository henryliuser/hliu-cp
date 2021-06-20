class Solution:
    def numberOfRounds(self, startTime: str, finishTime: str) -> int:
        def getHM(s):
            return int(s[0:2]), int(s[3:5])

        ans = 0
        lol = range(0, 61, 15)
        h, m = getHM(startTime)
        eh, em = getHM(finishTime)
        if (m % 15 != 0):
            for l in lol:
                if (l >= m):
                    m = l
                    if m == 60:
                        m = 0
                        h = (h+1) % 24
                    break
        if (em % 15 != 0):
            for l in reversed(lol):
                if (l <= em):
                    em = l
                    break

        while h != eh or m != em:
            for l in lol:
                if l > m:
                    m = l
                    ans += 1
                    if m == 60:
                        h = (h+1) % 24
                        m = 0
                    break

        return ans


            
