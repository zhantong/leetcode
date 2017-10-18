# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack = []
        result = []
        node = root
        while node or stack:
            if node:
                stack.append(node)
                result.append(node.val)
                node = node.right
            else:
                node = stack.pop()
                node = node.left
        result.reverse()
        return result
