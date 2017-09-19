class Solution:
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(len(nums)):
            current = 0
            j = i
            while nums[j] >= 0:
                nums[j], j = -1, nums[j]
                current += 1
            result = max(result, current)
        return result
