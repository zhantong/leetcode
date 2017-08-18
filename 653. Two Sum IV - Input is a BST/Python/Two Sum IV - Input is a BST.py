class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        candidates = set()
        stack = []
        while stack or root:
            if root:
                val = root.val
                if val in candidates:
                    return True
                else:
                    candidates.add(k - val)
                stack.append(root)
                root = root.left
            else:
                node = stack.pop()
                root = node.right
        return False
