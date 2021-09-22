# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def dfs(root, remaining):
            for x in remaining:
                root.left = TreeNode(x)
                remaining.remove(x)
                for y in remaining:

                dfs(root.left)
                root.right = Tree

        for x in range(n):
            pass
