# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def path_sum(root, result):
            if not root:
                return (0, result)
            left, result = path_sum(root.left, result)
            left = max(0, left)
            right, result = path_sum(root.right, result)
            right = max(0, right)
            result = max(result, left + right + root.val)
            return max(left, right) + root.val, result

        return path_sum(root, -sys.maxsize)[1]
