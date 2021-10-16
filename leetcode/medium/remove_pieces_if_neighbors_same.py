class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        cnt = {'A':0,'B':0}
        def proc(q):
            st = 0
            for c in colors:
                if c == q:
                    st += 1
                    if st > 2:
                        cnt[q] += 1
                else: st = 0
        proc('A')
        proc('B')
        return cnt['A'] > cnt['B']
