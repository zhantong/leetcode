# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def paths(root, path, result):
            if root.left is None and root.right is None:
                result.append(path + str(root.val))
            if root.left:
                paths(root.left, path + str(root.val) + '->', result)
            if root.right:
                paths(root.right, path + str(root.val) + '->', result)

        result = []
        if root:
            paths(root, '', result)
        return result
