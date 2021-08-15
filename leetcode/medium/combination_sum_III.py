class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        def dfs(i, curr, path):
            if curr == n and len(path) == k:
                return ans.append(path[:])
            if len(path) > k: return
            for x in range(i+1, 10):
                if curr + x > n: break
                path.append(x)
                dfs(x, curr+x, path)
                path.pop()
        dfs(0, 0, [])
        return ans
