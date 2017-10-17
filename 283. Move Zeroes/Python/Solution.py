class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = 0
        while i < len(nums) and nums[i] != 0:
            i += 1
        if i != len(nums):
            for (index, num) in enumerate(nums):
                if num != 0 and index > i:
                    nums[i] = num
                    nums[index] = 0
                    i += 1
