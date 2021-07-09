# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        if not root: return []
        ans = []
        def dfs(x, s, p):
            p.append(x.val)
            if not x.left and not x.right:
                if s == targetSum: ans.append(list(p))
                return p.pop(-1)
            L, R = x.left, x.right
            if L: dfs(L, s+L.val, p)
            if R: dfs(R, s+R.val, p)
            p.pop(-1)
        dfs(root, root.val, [])
        return ans
