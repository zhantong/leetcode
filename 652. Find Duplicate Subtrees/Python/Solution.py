class Solution:
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """

        def duplicate(root, memory, result):
            if not root:
                return '#'
            key = duplicate(root.left, memory, result) + ',' + \
                duplicate(root.right, memory, result) + ',' + str(root.val)
            if key not in memory:
                memory[key] = 0
            if memory[key] == 1:
                result.append(root)
            memory[key] += 1
            return key

        result = []
        duplicate(root, {}, result)
        return result
