# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:
        memo = {} # (id, robbed) : max can earn
        def dfs(node, can_rob):
            if not node: return 0
            i = (id(node), can_rob)
            si = (id(node), False)
            if i in memo: return memo[i]
            take = 0
            if can_rob:
                L = dfs(node.left, False)
                R = dfs(node.right, False)
                take = node.val + L + R
            L = dfs(node.left, True)
            R = dfs(node.right, True)
            skip = L + R
            memo[i] = max(take, skip)
            memo[si] = skip
            return memo[i]

        return dfs(root, True)

# @zhanweiting's solution on LeetCode discuss
class Solution:
    def rob(self, root: TreeNode) -> int:
        return max(self.dfs(root))

    def dfs(self, root: TreeNode):
        if not root:
            return (0, 0)
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        return (root.val + left[1] + right[1], max(left[0], left[1]) + max(right[0], right[1]))
