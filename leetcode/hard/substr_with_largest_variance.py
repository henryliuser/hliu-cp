# https://leetcode.com/contest/biweekly-contest-78/problems/substring-with-largest-variance/
# loop on pairs of characters (c1,c2). clump the groups together into alternating chunks of c1 and c2
# ignoring any other characters besides the pair
# aazzabbttttaababb -> (a,b) -> aaabbaababb -> [3, 2, 2, 1, 1, 2]
# negate every other count, then consider the prefix sum:
# -> [3, -2, 2, -1, 1, -2] -> [0, 3, 1, 3, 2, 3, 1]
# run kadane's to find the largest absolute value subarray sum of the prefix sum
# take the best answer
class Solution:
    def largestVariance(self, s: str) -> int:
        ans = 0
        N = len(s)
        for c1 in range(26):
            for c2 in range(c1 + 1, 26):
                iv = []
                flip = 1
                stk, last = 1, -1
                for i in range(N):
                    o = ord(s[i]) - ord('a')
                    if o not in [c1, c2]: continue
                    if last == -1:
                        last = o
                        continue
                    if o == last:
                        stk += 1
                    else:
                        iv += [flip * stk]
                        flip *= -1
                        stk = 1
                        last = o
                if last != -1:
                    iv += [flip*stk]

                M = len(iv)
                if M <= 1: continue
                ans = max(ans, max(map(abs, iv))-1)
                if M <= 2: continue

                mn = mx = l = r = 0
                for i in range(2): r += iv[i]
                for i in range(2, M):
                    r += iv[i]
                    l += iv[i-2]
                    ans = max(ans, r - mn)
                    ans = max(ans, abs(r - mx))
                    mn = min(mn, l)
                    mx = max(mx, l)

        return ans
