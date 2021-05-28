class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        mx = [0, 0]
        curr = [0, 0]
        last = -1
        for c in s:
            c = int(c)
            if c == last: curr[c] += 1
            else:
                if last != -1:
                    mx[last] = max(curr[last], mx[last])
                    curr[last] = 0
                curr[c] = 1
                last = c
        mx[last] = max(curr[last], mx[last])
        return mx[1] > mx[0]
