class Solution:
    def replaceDigits(self, s: str) -> str:
        ans = []
        for x in range(len(s)):
            if x % 2 == 0: ans.append(s[x])
            else: ans.append(chr(ord(s[x-1])+int(s[x])))
        return "".join(ans)
