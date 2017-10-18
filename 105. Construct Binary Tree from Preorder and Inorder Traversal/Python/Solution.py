# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder or not inorder:
            return None
        node = TreeNode(preorder.pop(0))
        index = inorder.index(node.val)
        node.left = self.buildTree(preorder, inorder[:index])
        node.right = self.buildTree(preorder, inorder[index + 1:])
        return node
