# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root: return False
        L, R = root.left, root.right
        if root.val == targetSum and not (L or R): return True
        L = self.hasPathSum(root.left, targetSum-root.val)
        R = self.hasPathSum(root.right, targetSum-root.val)
        if L or R: return True
        return False
