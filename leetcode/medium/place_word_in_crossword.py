class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        W = len(word)
        M, N = len(board), len(board[0])

        def canPlace(word):
            out=[[], []]
            dpH = [[0] * (N+1) for _ in range(M+1)]
            dpV = [[0] * (N+1) for _ in range(M+1)]
            for r in range(1, M+1):
                t = r % 2
                for c in range(1, N+1):
                    b = board[r-1][c-1]
                    if b == '#':
                        dpH[t][c] = dpV[t][c] = 0
                    elif b == ' ':
                        dpH[t][c] = dpH[t][c-1] + 1
                        dpV[t][c] = dpV[not t][c] + 1
                    elif b != ' ':
                        up = dpV[not t][c]
                        if up < W and b == word[up]: dpV[t][c] = up + 1
                        elif b == word[0]: dpV[t][c] = 1
                        else: dpV[t][c] = 0
                        left = dpH[t][c-1]
                        if left < W and b == word[left]: dpH[t][c] = left + 1
                        elif b == word[0]: dpH[t][c] = 1
                        else: dpH[t][c] = 0
                    if r >= M or board[r][c-1] == '#':
                        if dpV[t][c] == W:
                            if r-W == 0 or board[r-W-1][c-1] == '#':
                                return True
                    if c >= N or board[r-1][c] == '#':
                        if dpH[t][c] == W:
                            if c-W == 0 or board[r-1][c-W-1] == '#':
                                return True
                out[0].append(str(dpH[t]))
                out[1].append(str(dpV[t]))

        return canPlace(word) or canPlace(word[::-1])

                
