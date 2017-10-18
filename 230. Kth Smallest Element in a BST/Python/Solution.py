# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.k = k
        self.result = None

        def smallest(root):
            if not root:
                return
            smallest(root.left)
            self.k -= 1
            if not self.k:
                self.result = root.val
                return
            smallest(root.right)

        smallest(root)
        return self.result
