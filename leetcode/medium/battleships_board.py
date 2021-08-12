# count top left corners of ships only
# clever way to solve for Nx1 / 1xN ship sizes
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        ans = 0
        M, N = len(board), len(board[0])
        for r in range(M):
            for c in range(N):
                if board[r][c] != 'X': continue
                left = r == 0 or (r > 0 and board[r-1][c] != 'X')
                top  = c == 0 or (c > 0 and board[r][c-1] != 'X')
                if left and top:
                    ans += 1
        return ans
