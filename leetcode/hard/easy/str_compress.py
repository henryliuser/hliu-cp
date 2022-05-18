class Solution:
    def compress(self, chars: List[str]) -> int:
        ans = []
        streak = 0
        last = chars[0]
        for ch in chars:
            if ch == last:
                streak += 1
            else:
                ans.append(last)
                if streak != 1:
                    for x in list(str(streak)):
                        ans.append(x)
                streak = 1
                last = ch
        ans.append(last)
        if streak != 1:
            for x in list(str(streak)):
                ans.append(x)
        for x in range(len(ans)):
            chars[x] = ans[x]
        return len(ans)
                
