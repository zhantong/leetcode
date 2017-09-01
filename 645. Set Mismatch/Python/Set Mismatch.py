class Solution:
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        duplicate = 0
        miss = 0
        for num in nums:
            if nums[abs(num) - 1] < 0:
                duplicate = abs(num)
            else:
                nums[abs(num) - 1] *= -1
        for i in range(len(nums)):
            if nums[i] > 0:
                miss = i + 1
        return [duplicate, miss]
