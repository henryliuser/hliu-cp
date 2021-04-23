class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        # clean 2 pointers -- O(N) time, O(1) space
        ln = len(nums)
        ans = [1] * ln
        L = R = 1  # left, right products
        for i in range(ln):
            ans[i]  *= L
            ans[~i] *= R    # ~i = -i-1
            L *= nums[i]
            R *= nums[~i]
        return ans
        
        # 2-sided prefix product O(N) time O(N) space
        ln = len(nums)
        prep, prep2 = [1]*ln, [1]*ln
        for x in range(ln):
            n = nums[x]
            if x == 0: prep[x] = n
            else: prep[x] = prep[x-1] * n
        for x in range(ln-1, -1, -1):
            n = nums[x]
            if x == ln-1: prep2[x] = n
            else: prep2[x] = prep2[x+1] * n
        return [(prep[n-1] if n != 0 else 1) * (prep2[n+1] if n != ln-1 else 1) for n in range(ln)]

        # division solution -- O(N)
        ans, prod, z = [], 1, 0
        for x in nums:
            if x == 0: z += 1
            else: prod *= x
        if z > 1: return [0 for x in nums]
        for x in nums:
            if x == 0: ans.append(prod)
            elif z > 0: ans.append(0)
            else: ans.append(prod//x)
        return ans

        # naive solution -- O(N^2)
        ans = []
        for x in range(len(nums)):
            prod = 1
            for y in range(len(nums)):
                if y == x: continue
                prod *= nums[y]
            ans.append(prod)
        return ans
