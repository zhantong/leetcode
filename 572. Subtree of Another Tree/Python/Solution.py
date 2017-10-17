class Solution:
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """

        def is_same(s, t):
            if s is None and t is None:
                return True
            if s is None or t is None or s.val != t.val:
                return False
            return is_same(s.left, t.left) and is_same(s.right, t.right)

        if s is None:
            return False
        return is_same(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
