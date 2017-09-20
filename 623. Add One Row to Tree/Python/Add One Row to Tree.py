class Solution:
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """

        def add(root, current, v, d):
            if not root:
                return root
            if current == d - 1:
                temp_left = root.left
                new_left = TreeNode(v)
                new_left.left = temp_left
                root.left = new_left

                temp_right = root.right
                new_right = TreeNode(v)
                new_right.right = temp_right
                root.right = new_right
            else:
                add(root.left, current + 1, v, d)
                add(root.right, current + 1, v, d)

        if d == 1:
            new_root = TreeNode(v)
            new_root.left = root
            return new_root
        add(root, 1, v, d)
        return root
