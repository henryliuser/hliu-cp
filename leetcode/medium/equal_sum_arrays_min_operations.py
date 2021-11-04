# super instructive PQ question.
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        N, M = len(nums1), len(nums2)
        if N > 6*M or M > 6*N: return -1
        s1, s2 = sum(nums1), sum(nums2)
        if s1 == s2: return 0
        if s1 > s2:
            nums1, nums2 = nums2, nums1
            s1, s2 = s2, s1
        pq1 = [x-6 for x in nums1]  # minimize dist per element
        pq2 = [1-x for x in nums2]  # inverted for max-heap
        heapify(pq1), heapify(pq2)

        ans = 0
        while s1 < s2:
            a, b = -pq1[0], -pq2[0]
            who = pq1 if a > b else pq2
            s1 -= heapreplace(who, 0)
            ans += 1
        return ans
