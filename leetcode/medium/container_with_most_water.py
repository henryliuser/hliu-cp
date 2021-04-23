class Solution:
    def maxArea(self, height: List[int]) -> int:

        # O(N) 2 pointers
        ln = len(height)
        ans, i, j = 0, 0, ln -1
        while i != j:
            w, h1, h2 = j-i, height[i], height[j]
            ans = max(ans, w*min(h1,h2))
            if h1 <= h2: i += 1
            else: j -= 1
        return ans

        # N^2 TLE
        ans = 0
        ln = len(height)
        for i in range(ln):
            for j in range(i+1, ln):
                w, h = j-i, min(height[i], height[j])
                ans = max(ans, w*h)
        return ans
