# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        result = ''
        stack = []
        while root or stack:
            if root:
                result += str(root.val) + ' '
                stack.append(root)
                root = root.left
            else:
                node = stack.pop()
                root = node.right
        return result

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        data = [int(item) for item in data.split()]

        def construct(data, i, j):
            if i == j:
                return None
            node = TreeNode(data[i])
            split_index = i + 1
            while split_index < j and data[split_index] < data[i]:
                split_index += 1
            node.left = construct(data, i + 1, split_index)
            node.right = construct(data, split_index, j)
            return node

        return construct(data, 0, len(data))


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
