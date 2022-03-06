# https://leetcode.com/contest/weekly-contest-283/problems/create-binary-tree-from-descriptions/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, desc: List[List[int]]) -> Optional[TreeNode]:
        hasP = set()
        node = defaultdict(TreeNode)
        for p,c,l in desc:
            hasP |= {c}
            node[p].val = p
            node[c].val = c
            if l: node[p].left  = node[c]
            else: node[p].right = node[c]

        for u in node:
            if u not in hasP:
                return node[u]


            
