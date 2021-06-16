class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def check(guess):
            return sum(map(lambda x: ceil(x/guess), nums)) <= threshold

        lo, hi = 1, max(nums)
        while lo < hi:
            mid = (lo+hi)//2
            if check(mid): hi = mid
            else: lo = mid + 1
        return lo

            
