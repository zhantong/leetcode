# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def dfs(root, sum, result, current):
            current.append(root.val)
            sum -= root.val
            if sum == 0:
                if not root.left and not root.right:
                    result.append(current[:])
            if root.left:
                dfs(root.left, sum, result, current)
            if root.right:
                dfs(root.right, sum, result, current)
            current.pop()

        result = []
        if not root:
            return result
        dfs(root, sum, result, [])
        return result
