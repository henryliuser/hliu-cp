from collections import Counter
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        # sorting N^2, 1
        ln = len(nums)
        ans = []
        nums.sort()
        for i in range(ln-2):
            # skip duplicates
            if i > 0 and nums[i] == nums[i-1]: continue
            L, R = i+1, ln-1
            while L < R:
                a, b, c = nums[i], nums[L], nums[R]
                s = a + b + c
                if s < 0:   L += 1
                elif s > 0: R -= 1
                else:
                    ans.append( (a,b,c) )
                    while L < R and nums[L] == nums[L+1]: L += 1
                    while L < R and nums[R] == nums[R-1]: R -= 1
                    L, R = L+1, R-1
        return ans


        # hashing N^2, N
        if len(nums) < 3: return []
        s, ans = Counter(nums), set()
        for a in s:
            for b in s:
                if (v:=-a-b) in s:
                    if a == b and s[a] < 2: continue
                    count = s[v]
                    # count -= int(a == v) + int(b == v)
                    if a == v: count -= 1
                    if b == v: count -= 1
                    if count >= 1: ans.add(tuple(sorted([a,b,v])))
        return list(map(list, ans))
