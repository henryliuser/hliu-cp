class Solution:
    def diagonalSum(self, m: List[List[int]]) -> int:
        N = len(m)
        s = sum(m[x][x] + m[x][~x] for x in range(N))
        if N % 2 == 1:
            s -= m[N//2][N//2]
        return s

        # return sum(m[x][x] + m[x][~x] for x in range(len(m))) - (m[len(m)//2][len(m)//2] if len(m)%2 == 1 else 0)
