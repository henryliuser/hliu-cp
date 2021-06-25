class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        N = len(fruits)
        lo, ans = 0, 0
        curr = defaultdict(int)
        for hi in range(N):
            curr[fruits[hi]] += 1
            if len(curr) <= 2: ans = max(ans, hi-lo+1)
            while len(curr) > 2:
                curr[fruits[lo]] -= 1
                if curr[fruits[lo]] == 0:
                    curr.pop(fruits[lo])
                lo += 1
        return ans
