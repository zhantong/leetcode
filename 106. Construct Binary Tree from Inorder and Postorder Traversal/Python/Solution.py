# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder or not postorder:
            return None
        node = TreeNode(postorder.pop())
        index_inorder = inorder.index(node.val)
        node.right = self.buildTree(inorder[index_inorder + 1:], postorder)
        node.left = self.buildTree(inorder[:index_inorder], postorder)
        return node
