# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        ans = 0
        def sumTree(root):
            nonlocal ans
            if not root: return 0
            x = root.val + sumTree(root.left) + sumTree(root.right)
            ans = max(ans, x)
            return x
        sumTree(root)
        return ans
