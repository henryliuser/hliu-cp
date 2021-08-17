# backtracking with swaps
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        N = len(nums)
        def dfs(i, path):
            print(i, path)
            if i == N: return ans.append(path[:])
            for x in range(i, N):
                path[x], path[i] = path[i], path[x]
                dfs(i+1, path)
                path[x], path[i] = path[i], path[x]
        dfs(0, list(nums))
        return ans

# backtracking with seen
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        N = len(nums)
        path, seen = [], [False] * N
        def dfs():
            if len(path) == N:
                return ans.append(path[:])
            for x in range(N):
                if seen[x]: continue
                seen[x] = True
                path.append(nums[x])
                dfs()
                path.pop()
                seen[x] = False
        dfs()
        return ans
