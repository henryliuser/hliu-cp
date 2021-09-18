class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        N = len(changed)
        if N%2 != 0: return []
        changed.sort()
        og = []
        count = Counter(changed)
        for i in range(N):
            c = changed[i]
            cnt = count[c]
            cnt2 = count[c*2]
            if cnt > 0 and cnt2 > 0 and c != 0:
                og.append(c)
                count[c] -= 1
                count[c*2] -= 1
            if c == 0 and count[0] > 1:
                og.append(0)
                count[0] -= 2
        return og if len(og) == N//2 else []
