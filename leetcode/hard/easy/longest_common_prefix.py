class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        c = 0
        while True:
            try:
                first = strs[0][c]
                for s in strs:
                    if s[c] != first: return ans
                ans += first
                c += 1
            except: return ans
