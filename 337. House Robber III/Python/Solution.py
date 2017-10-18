# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def __init__(self):
        self.memory = {}

    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if root in self.memory:
            return self.memory[root]
        sub_sum = 0
        if root.left:
            sub_sum += self.rob(root.left.left) + self.rob(root.left.right)
        if root.right:
            sub_sum += self.rob(root.right.left) + self.rob(root.right.right)
        result = max(root.val + sub_sum, self.rob(root.left) + self.rob(root.right))
        self.memory[root] = result
        return result
