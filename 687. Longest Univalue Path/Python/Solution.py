# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def dfs(node, result):
            left = 0
            if node.left:
                left = dfs(node.left, result)
                left = left + 1 if node.left.val == node.val else 0
            right = 0
            if node.right:
                right = dfs(node.right, result)
                right = right + 1 if node.right.val == node.val else 0
            result[0] = max(result[0], left + right)
            return max(left, right)

        if not root:
            return 0
        result = [0]
        dfs(root, result)
        return result[0]
