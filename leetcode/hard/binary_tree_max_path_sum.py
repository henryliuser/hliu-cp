# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        ans = root.val
        def dfs(n) -> int:
            nonlocal ans
            if not n: return 0
            L, R = n.left, n.right
            mps = n.val
            mpsL = max(dfs(L), 0)
            mpsR = max(dfs(R), 0)
            m = mps + max(mpsL, mpsR)
            ans = max(ans, mps + mpsL + mpsR)
            ans = max(ans, m)
            return m
        dfs(root)
        return ans
            
