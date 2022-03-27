# https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
class Solution:
    def minDeletion(self, A) -> int:
        d = 0
        st = []
        N = len(A)
        for i, x in enumerate(A):
            p = (i + d) % 2
            if st and p and st[-1] == x:  # NOT while lol
                st.pop()
                d += 1
            st += [x]
        return d + len(st) % 2
