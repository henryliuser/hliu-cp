class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        N = len(changed)
        if N%2 != 0: return []
        # changed.sort()
        og = []
        count = Counter(changed)
        for i in range(N):
            c = changed[i]
            c1 = count[c]
            c2 = count[c//2]
            if c2 == 0 and count[c*2] != 0:
                og.append(c)
                count[c] -= 1
                count[c*2] -= 1
            elif c%2 != 0 and count[c*2] != 0:
                og.append(c)
                count[c] -= 1
                count[c*2] -= 1
            elif c1 != c2: return []
        return og if len(og) == N//2 else []
    
