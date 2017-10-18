# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root.left is None and root.right is None:
            return -1
        left = self.findSecondMinimumValue(
            root.left) if root.val == root.left.val else root.left.val
        right = self.findSecondMinimumValue(
            root.right) if root.val == root.right.val else root.right.val
        if left == -1 and right == -1:
            return -1
        if left == -1:
            return right
        if right == -1:
            return left
        return min(left, right)
