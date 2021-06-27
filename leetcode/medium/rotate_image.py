class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        m = matrix
        N = len(m)

        for r in range(N//2):  # vertical reflect
            for c in range(N):
                m[r][c], m[~r][c] = m[~r][c], m[r][c]

        for r in range(N-1, 0, -1):  # diagonal reflect
            for c in range(r):
                m[r][c], m[c][r] = m[c][r], m[r][c]
