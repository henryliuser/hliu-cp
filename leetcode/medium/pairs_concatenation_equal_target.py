class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        ans = 0
        T = len(target)
        pre, suf = Counter(), Counter()
        for num in nums:
            ln = len(num)
            s = target.startswith(num)
            e = target.endswith(num)
            if s: ans += suf[T - ln]
            if e: ans += pre[T - ln]
            if s: pre[ln] += 1
            if e: suf[ln] += 1
        return ans
