class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = 0
        N = len(heights)
        pse = [-1] * N
        nse = [-1] * N
        def process(r, se):
            st = []
            for i in r:
                x = heights[i]
                while st and x < heights[st[-1]]:
                    se[st.pop()] = i
                st.append(i)

        process(range(N), nse)
        process(reversed(range(N)), pse)
        for i,h in enumerate(heights):
            left  = pse[i] + 1
            right = nse[i] - 1
            if right == -2: right = N-1
            ans = max(ans, h * (right-left+1))
        return ans
            
