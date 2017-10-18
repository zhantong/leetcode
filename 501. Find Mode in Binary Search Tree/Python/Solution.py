# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack = []
        result = []
        if not root:
            return result
        prev = None
        count = 0
        max_count = 0
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                if prev is None:
                    prev = root.val
                    count = 1
                elif prev == root.val:
                    count += 1
                else:
                    if count == max_count:
                        result.append(prev)
                    elif count > max_count:
                        max_count = count
                        result = [prev]
                    count = 1
                    prev = root.val
                root = root.right
        if count == max_count:
            result.append(prev)
        elif count > max_count:
            result = [prev]
        return result
