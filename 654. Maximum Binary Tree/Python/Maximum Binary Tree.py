class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """

        def construct(nums, start, end):
            if start == end:
                return None
            max = -sys.maxsize
            max_index = -1
            for i in range(start, end):
                if nums[i] > max:
                    max = nums[i]
                    max_index = i
            root = TreeNode(max)
            root.left = construct(nums, start, max_index)
            root.right = construct(nums, max_index + 1, end)
            return root

        return construct(nums, 0, len(nums))
