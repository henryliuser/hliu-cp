class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        N = len(temperatures)
        ans = [0] * N
        stack = []
        for i,t in enumerate(temperatures):
            while stack and t > temperatures[stack[-1]]:
                sc = stack.pop()
                ans[sc] = i - sc
            stack.append(i)
        return ans
