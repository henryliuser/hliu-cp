# https://leetcode.com/problems/generate-parentheses/
# use balance thing
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def dfs(o, c, bal, p):
            if o == c == bal == 0:
                return ans.append(''.join(p))
            if o:
                p += ['(']
                dfs(o-1, c, bal+1, p)
                p.pop()
            else: return dfs(0, 0, 0, p+[')'*c])
            if c and bal > 0:
                p += [')']
                dfs(o, c-1, bal-1, p)
                p.pop()

        dfs(n - 1, n, 1, ['('])
        return ans
