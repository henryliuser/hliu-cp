class Solution:
    def largestOddNumber(self, num: str) -> str:
        N = len(num)
        x = N-1
        while (int(num[x]) % 2 == 0):
            x -= 1
            if x == -1: return ""

        return str(num[:x+1])
        
