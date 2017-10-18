# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        if not root:
            return result
        queue = collections.deque()
        queue.append(root)
        left_to_right = True
        while queue:
            size = len(queue)
            current = []
            for i in range(size):
                node = queue.popleft()
                current.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if not left_to_right:
                current = list(reversed(current))
            result.append(current)
            left_to_right = not left_to_right
        return result
