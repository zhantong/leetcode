class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if not root:
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
            if count_current_level:
                result.append(sum_current_level / count_current_level)
        return result
