class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        ln, ans = len(A), 0
        pre = [0,A[0]]
        for x in range(1, ln): pre.append(pre[-1]+A[x])

        L, M = L-1, M-1
        for x in range(ln-L):
            for y in range(ln-M):
                if x <= y <= x+L or x <= y+M <= x+L: continue
                if y <= x <= y+M or y <= x+L <= y+M: continue
                val = pre[x+L+1]-pre[x] + pre[y+M+1]-pre[y]
                ans = max(ans, val)
        return ans


        
