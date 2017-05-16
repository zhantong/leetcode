# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.result = sys.maxsize
        stack = []
        prev = None
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                node = stack.pop()
                if prev is not None:
                    self.result = min(self.result, abs(node.val - prev))
                prev = node.val
                root = node.right
        return self.result
