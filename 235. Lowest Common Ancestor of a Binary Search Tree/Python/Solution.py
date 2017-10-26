# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while root:
            if (p.val < root.val and q.val > root.val) or (p.val > root.val and q.val < root.val) or (
                    p.val == root.val) or (q.val == root.val):
                return root
            if p.val < root.val and q.val < root.val:
                root = root.left
            if p.val > root.val and q.val > root.val:
                root = root.right
