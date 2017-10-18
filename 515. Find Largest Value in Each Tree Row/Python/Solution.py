# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        queue = collections.deque()
        queue.append(root)
        result = []
        while queue:
            size = len(queue)
            current_max = queue[0].val
            for i in range(size):
                node = queue.popleft()
                if node.val > current_max:
                    current_max = node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(current_max)
        return result
