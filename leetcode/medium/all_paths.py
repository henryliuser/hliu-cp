class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        N = len(graph)
        paths = []
        def dfs(node, path):
            for e in graph[node]:
                path.append(e)
                if e == N-1:
                    paths.append(path[:])
                else: dfs(e, path)
                path.pop()
        dfs(0, [0])
        return paths
