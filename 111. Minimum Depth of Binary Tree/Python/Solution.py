# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        depth = -1
        queue = collections.deque()
        queue.append(root)
        while queue:
            depth += 1
            current_size = len(queue)
            print(depth, queue)
            for i in range(0, current_size):
                node = queue.popleft()
                if node.left is None and node.right is None:
                    return depth + 1
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return depth + 1
