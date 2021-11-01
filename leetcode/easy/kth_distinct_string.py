# clean. python dicts preserve insertion order
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        c = Counter(arr)
        s = list(x for x in c if c[x] == 1)
        if len(s) < k: return ""
        return s[k-1]

# manual
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        d = defaultdict(list)
        for i,a in enumerate(arr):
            d[a].append(i)
        q = []
        for x in d:
            if len(d[x]) == 1:
                q.append(d[x][0])
        q.sort()
        if len(q) < k: return ""
        return arr[q[k-1]]
