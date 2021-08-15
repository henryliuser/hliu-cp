class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        def dfs(i, path):
            if len(path) == k:
                return ans.append(path[:])
            for x in range(i+1, n+1):
                path.append(x)
                dfs(x, path)
                path.pop()
        dfs(0, [])
        return ans
