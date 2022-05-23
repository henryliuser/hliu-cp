# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        s = set()
        def dfs(x):
            if not x: return False
            if k-x.val in s: return True
            s.add(x.val)
            return dfs(x.left) or dfs(x.right)
        return dfs(root)
