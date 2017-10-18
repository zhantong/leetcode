class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)
        i = 1
        while i < len(nums) and nums[i] == nums[i - 1]:
            i += 1
        if i == len(nums):
            return 1
        is_increase = nums[0] > nums[i]
        result = 2
        prev = nums[i]
        for num in nums[i + 1:]:
            if is_increase:
                if num > prev:
                    result += 1
                    prev = num
                    is_increase = False
                elif num < prev:
                    prev = num
            else:
                if num < prev:
                    result += 1
                    prev = num
                    is_increase = True
                elif num > prev:
                    prev = num
        return result
