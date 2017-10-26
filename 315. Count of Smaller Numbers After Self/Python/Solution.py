class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        class Node:
            def __init__(self, value):
                self.value = value
                self.count_left = 0
                self.count_duplicate = 1
                self.left = None
                self.right = None

        def insert(node, num, result, i, count):
            if not node:
                node = Node(num)
                result[i] = count
            elif node.value == num:
                result[i] = count + node.count_left
                node.count_duplicate += 1
            elif node.value > num:
                node.count_left += 1
                node.left = insert(node.left, num, result, i, count)
            else:
                count += node.count_left + node.count_duplicate
                node.right = insert(node.right, num, result, i, count)
            return node

        result = [None] * len(nums)
        root = None
        for i in range(len(nums) - 1, -1, -1):
            root = insert(root, nums[i], result, i, 0)
        return result
