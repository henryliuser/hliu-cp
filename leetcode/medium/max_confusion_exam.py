class Solution:
    def maxConsecutiveAnswers(self, ak: str, k: int) -> int:
        N = len(ak)
        def slide(ch):
            ans = curr = i = 0
            for j in range(N):
                if ak[j] == ch:
                    curr += 1
                while curr > k:
                    curr -= ak[i] == ch
                    i += 1
                ans = max(ans, j-i+1)
            return ans
        return max(slide('T'), slide('F'))







        
