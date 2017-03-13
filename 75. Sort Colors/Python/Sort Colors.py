class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        left = 0
        while left < len(nums) and nums[left] == 0:
            left += 1
        right = len(nums) - 1
        while right >= 0 and nums[right] == 2:
            right -= 1
        current = left
        while current <= right and left <= right:
            if nums[current] == 0:
                if current == left:
                    current += 1
                else:
                    nums[left], nums[current] = nums[current], nums[left]
                left += 1
            elif nums[current] == 2:
                if current == right:
                    current += 1
                else:
                    nums[right], nums[current] = nums[current], nums[right]
                right -= 1
            else:
                current += 1
