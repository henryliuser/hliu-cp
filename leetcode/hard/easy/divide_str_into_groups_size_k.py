# https://leetcode.com/contest/weekly-contest-276/problems/divide-a-string-into-groups-of-size-k/
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans = []
        N = len(s)
        q = (k - N % k) % k
        s = s + fill * q
        for i in range(0, N+q, k):
            ans += [ s[i:i+k] ]
        return ans
