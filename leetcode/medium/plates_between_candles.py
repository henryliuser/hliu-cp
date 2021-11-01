# can do mono-stack to solve in N + Q log N
# binary search passes.
class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        ans = []
        n = len(s)
        pre = [0] + [0] * n
        candles = []
        for i, x in enumerate(s):
            if x == '|':
                candles.append(i)
            pre[i+1] = pre[i] + int(x == '*')

        for L, R in queries:
            a = bisect_left(candles, L)
            b = bisect_left(candles, R)
            if b == len(candles) or candles[b] > R:
                b -= 1
            if candles[a] >= R or a > b or a == b or candles[b] <= L:
                ans.append(0)
                continue
            x, y = candles[a], candles[b]
            ans.append(pre[y] - pre[x])
            
        return ans
