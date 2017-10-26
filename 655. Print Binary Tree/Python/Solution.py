class Solution:
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        def get_depth(root):
            if not root:
                return 0
            return max(get_depth(root.left), get_depth(root.right)) + 1

        depth = get_depth(root)
        self.result = [[''] * (2 ** depth - 1) for _ in range(depth)]

        def print_tree(root, row, depth, col):
            self.result[row][col] = str(root.val)
            row += 1
            if root.left:
                print_tree(root.left, row, depth, col - 2 ** (depth - row - 1))
            if root.right:
                print_tree(root.right, row, depth, col + 2 ** (depth - row - 1))

        print_tree(root, 0, depth, 2 ** (depth - 1) - 1)
        return self.result
