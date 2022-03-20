# https://leetcode.com/contest/weekly-contest-285/problems/count-collisions-on-a-road/
class Solution:
    def countCollisions(self, directions: str) -> int:
        st = []
        ans = 0
        for d in directions:
            if d == 'R':
                st += [d]
            elif d == 'L' and st and st[-1] == 'S':
                ans += 1
            else:
                while st and st[-1] == 'R':
                    if d == 'S':
                        ans += 1
                    if d == 'L':
                        ans += 2
                        d = 'S'
                    st.pop()
                st += [d]
        return ans
