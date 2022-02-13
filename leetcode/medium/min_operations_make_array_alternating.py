# https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/
class Solution:
    def minimumOperations(self, A: List[int]) -> int:
        N = len(A)
        if N == 1: return 0

        cnt = [defaultdict(int), defaultdict(int)]
        for i in range(N):
            cnt[i%2][ A[i] ] += 1

        E = sorted(cnt[0], key=lambda x: (-cnt[0][x],x) )
        O = sorted(cnt[1], key=lambda x: (-cnt[1][x],x) )

        ue, uo = map(len, cnt)
        ne = N//2 + N%2
        no = N//2

        a = ne - cnt[0][E[0]]  # best of E
        b = no - cnt[1][O[0]]  # best of O
        if E[0] != O[0]:  return a + b
        if ue == uo == 1: return min(ne, no)
        if ue == 1: return min(ne + b, no-cnt[1][O[1]])
        if uo == 1: return min(no + a, ne-cnt[0][E[1]])
        return min(ne-cnt[0][E[1]] + b, no-cnt[1][O[1]] + a)
