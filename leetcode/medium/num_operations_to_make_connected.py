class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        parent = [-1] * n
        size = [1] * n
        count = n

        def union(a, b):
            nonlocal count
            a,b = find(a), find(b)
            if a == b: return False
            if size[a] < size[b]: a,b = b,a
            parent[b] = a
            size[a] += size[b]
            count -= 1
            return True
        def find(a):
            if parent[a] == -1:
                return a
            parent[a] = find(parent[a])
            return parent[a]

        surplus = 0
        for a,b in connections:
            surplus += int(not union(a,b))

        needed = count - 1
        if surplus < needed: return -1
        return needed
