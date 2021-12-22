class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        # solves for the general case
        # didn't see that they're already sorted :)
        ans = 0
        M = len(nums2)
        B = sorted( [(y,i) for i,y in enumerate(nums2)] )
        sfx = [t[1] for t in B]
        for i in range(M-2, -1, -1):
            sfx[i] = max(sfx[i], sfx[i+1])

        for i,x in enumerate(nums1):
            j = bisect_left( B, (x,-1) )21
            if j == M: continue
            ans = max(ans, sfx[j] - i)

        return ans
