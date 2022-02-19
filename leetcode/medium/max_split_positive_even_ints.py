# https://leetcode.com/contest/biweekly-contest-72/problems/maximum-split-of-positive-even-integers/
class Solution:
    def maximumEvenSplit(self, s: int) -> List[int]:
        if s % 2: return []

        cur = s
        ans = set()
        for x in range(2, s+1, 2):
            if cur < x: break  # lol
            if x in ans or cur-x in ans or cur-x <= 0 or x == cur-x:
                continue
            cur -= x
            ans.add(x)
        return list(ans | {cur})
