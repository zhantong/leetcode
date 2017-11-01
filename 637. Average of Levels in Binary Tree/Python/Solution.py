# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if root is None:
            return []
        queue = collections.deque()
        result = []
        queue.append(root)
        while queue:
            sum_current_level = 0
            count_current_level = len(queue)
            for _ in range(count_current_level):
                current = queue.popleft()
                sum_current_level += current.val
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
            if count_current_level != 0:
                result.append(sum_current_level / count_current_level)
        return result
