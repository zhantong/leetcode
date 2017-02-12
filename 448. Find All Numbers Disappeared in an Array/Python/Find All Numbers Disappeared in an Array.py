class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for num in nums:
            index = num if num > 0 else -num
            index -= 1
            if nums[index] > 0:
                nums[index] = -nums[index]
        result = []
        for (index, num) in enumerate(nums):
            if num > 0:
                result.append(index + 1)
        return result
