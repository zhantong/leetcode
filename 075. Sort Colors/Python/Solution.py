class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        left = 0
        right = len(nums) - 1
        middle = 0
        while middle <= right:
            while nums[middle] == 2 and middle < right:
                nums[middle], nums[right] = nums[right], nums[middle]
                right -= 1
            while nums[middle] == 0 and middle > left:
                nums[middle], nums[left] = nums[left], nums[middle]
                left += 1
            middle += 1
