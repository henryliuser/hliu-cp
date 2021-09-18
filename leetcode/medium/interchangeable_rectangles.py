class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        ans = 0
        count = defaultdict(int)
        for w,h in rectangles:
            g = gcd(w, h)
            k = (w//g, h//g)
            ans += count[k]
            count[k] += 1
        return ans
