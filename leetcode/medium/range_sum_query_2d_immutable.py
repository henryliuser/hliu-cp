class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        M, N = len(matrix), len(matrix[0])
        self.mtx = [[0]*(N+1) for _ in range(M+1)]
        for i in range(1, M+1):
            for j in range(1, N+1):
                self.mtx[i][j] = matrix[i-1][j-1] + self.mtx[i][j-1]
        for i in range(1, M+1):
            for j in range(1, N+1):
                self.mtx[i][j] += self.mtx[i-1][j]

    def sumRegion(self, a: int, b: int, c: int, d: int) -> int:
        all  = self.mtx[c+1][d+1]
        top  = self.mtx[a][d+1]
        left = self.mtx[c+1][b]
        over = self.mtx[a][b]
        return all - top - left + over


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
