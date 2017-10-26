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
        :rtype: int
        """
        def path(root, check_list):
            if root is None:
                return 0
            count = 0
            for i in range(0, len(check_list)):
                check_list[i] -= root.val
                if check_list[i] == 0:
                    count += 1
            count += path(root.left, check_list + [sum])
            count += path(root.right, check_list + [sum])
            return count

        return path(root, [sum])
