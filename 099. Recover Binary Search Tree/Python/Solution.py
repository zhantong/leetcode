# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        pre = None
        first = None
        second = None
        while root:
            if root.left:
                temp = root.left
                while temp.right and temp.right != root:
                    temp = temp.right
                if not temp.right:
                    temp.right = root
                    root = root.left
                else:
                    temp.right = None
                    if pre and pre.val > root.val:
                        if first:
                            second = root
                        else:
                            first = pre
                            second = root
                    pre = root
                    root = root.right
            else:
                if pre and pre.val > root.val:
                    if first:
                        second = root
                    else:
                        first = pre
                        second = root
                pre = root
                root = root.right
        if first and second:
            first.val, second.val = second.val, first.val
