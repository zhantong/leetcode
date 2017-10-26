# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def numbers(root, prev_sum):
            if not root:
                return 0
            prev_sum = prev_sum * 10 + root.val
            if not root.left and not root.right:
                return prev_sum
            return numbers(root.left, prev_sum) + numbers(root.right, prev_sum)

        return numbers(root, 0)
