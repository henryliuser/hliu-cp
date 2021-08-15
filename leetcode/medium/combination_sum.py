class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        N = len(candidates)
        def dfs(i, curr, path):
            if curr == target:
                return ans.append(path[:])
            for x in range(i, N):
                num = candidates[x]
                if curr + num > target: break
                path.append(num)
                dfs(x, curr+num, path)
                path.pop()
        dfs(0, 0, [])
        return ans


# pure recursive, very slow running time

#         ans = []
#         candidates.sort()
#         N = len(candidates)
#         def dfs(i, curr, skip, path):
#             c[0] += 1
#             if curr > target: return
#             if i >= N: return
#             if skip: dfs(i+1, curr, True, path)
#             num = candidates[i]
#             path.append(num)
#             curr += num
#             if curr == target:
#                 ans.append(path[:])
#             dfs(i+1, curr, True, path)
#             dfs(i, curr, False, path)
#             path.pop()
#         dfs(0, 0, True, [])
#         return ans
