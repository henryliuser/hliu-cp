class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        c = defaultdict(int)
        for A in map(set, [nums1, nums2, nums3]):
            for n in A:
                c[n] += 1
        return [k for k in c if c[k] >= 2]
