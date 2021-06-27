class Solution:
    def sortString(self, s: str) -> str:
        ans = []
        count = defaultdict(int)
        for ch in s: count[ch] += 1

        while len(count) > 0:
            for ch in sorted(count):
                ans.append(ch)
                count[ch] -= 1
                if count[ch] == 0:
                    count.pop(ch)
            for ch in reversed(sorted(count)):
                ans.append(ch)
                count[ch] -= 1
                if count[ch] == 0:
                    count.pop(ch)
        return "".join(ans)
                
