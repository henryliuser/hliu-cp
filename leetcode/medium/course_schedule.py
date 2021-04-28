from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for x in range(numCourses)]
        indeg = defaultdict(int)
        # print(graph)
        for x in range(numCourses):
            indeg[x] = 0
        for edge in prerequisites:
            graph[edge[0]].append(edge[1])
            indeg[edge[1]] += 1

        q = []
        for k,v in indeg.items():
            if v == 0: q.append(k)

        c = 0
        while q:
            a = q.pop(0)
            c += 1
            for x in graph[a]:
                indeg[x] -= 1
                if indeg[x] == 0:
                    q.append(x)
        return c == numCourses
