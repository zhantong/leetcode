class Solution:
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = 0
        queue = collections.deque()
        if root:
            queue.append((root, 1))
        while queue:
            result = max(result, queue[-1][1] - queue[0][1] + 1)
            size = len(queue)
            for _ in range(size):
                current, id = queue.popleft()
                if current.left:
                    queue.append((current.left, 2 * id))
                if current.right:
                    queue.append((current.right, 2 * id + 1))
        return result
