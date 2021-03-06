class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        count = Counter(candidates)
        nums = sorted(count)
        N = len(nums)
        def dfs(i, curr, path):
            if curr == target:
                return ans.append(path[:])
            for x in range(i, N):
                q = nums[x]
                if curr+q > target: break
                if count[q] <= 0: continue
                count[q] -= 1
                path.append(q)
                dfs(x, curr+q, path)
                path.pop()
                count[q] += 1
        dfs(0, 0, [])
        return ans



# neater, but I don't understand it really

# class Solution:
#     def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
#         ans = []
#         nums = sorted(candidates)
#         N = len(nums)
#         def dfs(i, curr, path):
#             if curr == target:
#                 return ans.append(path[:])
#             for x in range(i, N):
#                 q = nums[x]
#                 if curr+q > target: break
#                 if x > i and q == nums[x-1]: continue
#                 path.append(q)
#                 dfs(x+1, curr+q, path)
#                 path.pop()
#         dfs(0, 0, [])
#         return ans
