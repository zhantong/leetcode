# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        sum = self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
        if root.left and root.left.left is None and root.left.right is None:
            sum += root.left.val
        return sum
