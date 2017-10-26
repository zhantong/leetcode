# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def generate(start, end):
            result = []
            if start > end:
                return [None]
            for i in range(start, end + 1):
                lefts = generate(start, i - 1)
                rights = generate(i + 1, end)
                for left in lefts:
                    for right in rights:
                        root = TreeNode(i)
                        root.left = left
                        root.right = right
                        result.append(root)
            return result

        if n == 0:
            return []
        return generate(1, n)
