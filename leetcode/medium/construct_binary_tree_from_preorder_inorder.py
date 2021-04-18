# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # recursive
        if inorder:
            # inorder goes:  left root right
            # preorder goes: root left right
            rIdx = inorder.index(preorder.pop(0)) # find root within inorder
            root = TreeNode(inorder[rIdx])

            # generate entire left side
            root.left = self.buildTree(preorder, inorder[:rIdx])

            # generate entire right side
            root.right = self.buildTree(preorder, inorder[rIdx+1:])
            return root
