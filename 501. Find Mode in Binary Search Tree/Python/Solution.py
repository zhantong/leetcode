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

        def mode(root, result, prev, current_count, max_count):
            if root is None:
                return prev, current_count, max_count
            prev, current_count, max_count = mode(root.left, result, prev, current_count, max_count)
            if prev is not None and prev == root.val:
                current_count += 1
            else:
                current_count = 1
            prev = root.val
            if current_count > max_count:
                max_count = current_count
                del result[:]
                result.append(root.val)
            elif current_count == max_count:
                result.append(root.val)
            prev, current_count, max_count = mode(root.right, result, prev, current_count, max_count)
            return prev, current_count, max_count

        result = []
        mode(root, result, None, 0, 0)
        return result
