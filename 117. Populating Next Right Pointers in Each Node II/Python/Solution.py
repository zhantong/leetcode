# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None


class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        head = None
        current = root
        level_prev = None
        while current:
            while current:
                if current.left:
                    if level_prev:
                        level_prev.next = current.left
                    else:
                        head = current.left
                    level_prev = current.left
                if current.right:
                    if level_prev:
                        level_prev.next = current.right
                    else:
                        head = current.right
                    level_prev = current.right
                current = current.next
            current = head
            level_prev = None
            head = None
