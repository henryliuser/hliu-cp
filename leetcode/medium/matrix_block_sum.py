class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        M, N = len(mat), len(mat[0])
        pre = [[0] * (N+1) for _ in range(M+1)]

        for r in range(1, M+1):
            for c in range(1, N+1):
                val = mat[r-1][c-1]
                pre[r][c] = pre[r][c-1] + val
        for r in range(1, M+1):
            for c in range(1, N+1):
                pre[r][c] += pre[r-1][c]

        ans = [[0] * N for _ in range(M)]
        for i in range(1,M+1):
            for j in range(1,N+1):
                a,b = max(i-k, 1), max(j-k, 1)
                c,d = min(i+k, M), min(j+k, N)
                s = pre[c][d] - pre[a-1][d] - pre[c][b-1] + pre[a-1][b-1]
                ans[i-1][j-1] = s

        return ans


#  1  2  3
#  4  5  6
#  7  8  9
#
#  1  3  6
#  10 15 21
#  28 36 45
