# https://leetcode.com/problems/adding-spaces-to-a-string/
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        q = set(spaces)
        for i in range(len(s)):
            if i in q: ans.append(' ')
            ans.append(s[i])
        return "".join(ans)
        
