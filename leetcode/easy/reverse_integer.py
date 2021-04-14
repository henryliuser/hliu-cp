class Solution:
    # bad question
    def reverse(self, x: int) -> int:
        ans = 0
        p = pow(2,31)
        # math solution
        while x:
            ans *= 10
            ans += x % 10
            x //= 10
        if ans < -p or ans > p-1: return 0
        else: return ans

        # strings solution, /shrug
        s = str(x)
        negative = False
        if s[0] == '-':
            ans = -int("".join(c for c in str(x)[1::][::-1]))
        else:
            ans = int("".join(c for c in str(x)[::-1]))
        if ans < -(p:=pow(2,31)) or ans > p: return 0
        else: return ans
