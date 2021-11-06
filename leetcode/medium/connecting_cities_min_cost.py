class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        count = n
        parent = [-1] * n
        size = [1] * n
        def union(a, b):
            nonlocal count
            a, b = find(a), find(b)
            if a == b: return False
            if size[a] < size[b]: a,b = b,a
            parent[b] = a
            size[a] += size[b]
            count -= 1
            return True
        def find(a):
            if parent[a] == -1: return a
            parent[a] = find(parent[a])
            return parent[a]

        ans = 0
        connections.sort(key = lambda x : x[2])
        for u,v,c in connections:
            if union(u-1,v-1): ans += c
            if count == 1: return ans
        return -1
