class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 2 pointer, O(M+N)
        m, n = len(nums1), len(nums2)
        mid = m+n
        even = mid % 2 == 0
        i = j = c = 0
        L = 0
        while i < m and j < n:
            a, b = nums1[i], nums2[j]
            if a <= b:
                if not even and c == mid // 2: return a
                elif c == mid//2 - 1: L = a
                elif c == mid//2: return (L+a)/2
                i += 1
            if b < a:
                if not even and c == mid // 2: return b
                elif c == mid//2 - 1: L = b
                elif c == mid//2: return (L+b)/2
                j += 1
            c += 1
        def finish(count, arr):
            nonlocal c, L
            while count < len(arr):
                a = arr[count]
                if not even and c == mid//2: return a
                elif c == mid//2 - 1: L = a
                elif c == mid//2: return (L+a)/2
                count, c = count+1, c+1
        if i < m: return finish(i, nums1)
        return finish(j, nums2)


#         # brute force, works for some reason...
        s = sorted(nums1 + nums2)
        ls = len(s)
        return s[ls//2] if ls % 2 == 1 else (s[ls//2-1]+s[ls//2]) / 2
