class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        ans = 1
        N = len(nums)

        def prime_factors(x):
            for i in range(2, int(math.sqrt(x))+1):
                if x % i == 0:
                    return prime_factors(x//i) | {i}
            return {x}

        parent = [-1] * N
        size   = [1]  * N
        def union(a, b):
            nonlocal ans
            a, b = find(a), find(b)
            if a == b: return
            if size[a] < size[b]: a,b = b,a
            parent[b] = a
            size[a] += size[b]
            ans = max(ans, size[a])

        def find(a):
            if parent[a] == -1: return a
            parent[a] = find(parent[a])
            return parent[a]


        groups = defaultdict(list)
        for i,n in enumerate(nums):
            for f in prime_factors(n):
                groups[f].append(i)
        for p,g in groups.items():
            x = g[0]
            for i in range(1, len(g)):
                union(x, g[i])

        return ans
