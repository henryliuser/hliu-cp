# https://leetcode.com/contest/weekly-contest-273/problems/recover-the-original-array/
class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        ks = set()
        nums.sort()
        N = len(nums)
        for j in range(1,N):
            dx = nums[j] - nums[0]
            if dx % 2 or dx // 2 == 0: continue
            ks.add( dx // 2 )

        for k in ks:
            cnt = defaultdict(int)
            for x in nums: cnt[x] += 1
            c = N//2
            res = []
            for x in nums:
                y = x + 2 *k
                if cnt[x] == 0: continue
                if cnt[y] == 0: continue
                cnt[y] -= 1
                cnt[x] -= 1
                res += [x + k]
                c -= 1

            if c == 0:
                return res
