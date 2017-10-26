# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def sum_and_tilt(root):
            if not root:
                return 0, 0
            sum_left, tilt_left = sum_and_tilt(root.left)
            sum_right, tilt_right = sum_and_tilt(root.right)
            return sum_left + sum_right + root.val, abs(sum_left - sum_right) + tilt_left + tilt_right

        sum_tree, tilt_tree = sum_and_tilt(root)
        return tilt_tree
