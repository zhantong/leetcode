# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        depth_left = 0
        node_left = root
        while node_left:
            depth_left += 1
            node_left = node_left.left
        depth_right = 0
        node_right = root
        while node_right:
            depth_right += 1
            node_right = node_right.right
        if depth_left == depth_right:
            return 2 ** depth_left - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
