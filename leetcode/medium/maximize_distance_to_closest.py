# https://leetcode.com/problems/maximize-distance-to-closest-person/
class Solution:
    def maxDistToClosest(self, A: List[int]) -> int:
        N = len(A)
        res = [float('inf')] * N

        def process(loop, st=[]):
            for i in loop:
                while st and A[st[-1]] < A[i]:
                    j = st.pop()
                    res[j] = min(res[j], abs(i-j))
                st += [i]

        process(range(N))
        process(range(N-1,-1,-1))
        return max(x for x in ans if x != float('inf'))
