# pretty annoying edge cases, but a good problem.
# harder than i thought.
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        s = sum(rolls)
        sn = mean * (m+n) - s
        if n*6 < sn: return []
        if n > sn: return []
        for q in range(1,8):
            if n * q > sn: break
        q-=1
        ans = [q] * n
        for i in range(sn - q*n):
            ans[i%n] += 1

        return ans
