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

        def serial(node, result):
            if node:
                result.append(str(node.val))
                serial(node.left, result)
                serial(node.right, result)
            else:
                result.append('#')

        result = []
        serial(root, result)
        return ' '.join(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """

        def deserail(que):
            value = que.popleft()
            if value == '#':
                return None
            node = TreeNode(int(value))
            node.left = deserail(que)
            node.right = deserail(que)
            return node

        que = collections.deque(data.split())
        return deserail(que)


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
