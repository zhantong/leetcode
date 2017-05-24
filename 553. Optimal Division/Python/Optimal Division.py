class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        length = len(nums)
        result = ''
        if length > 0:
            result += str(nums[0])
        if length > 1:
            result += '/'
        if length > 2:
            result += '('
        for i in range(1, length - 1):
            result += str(nums[i]) + '/'
        if length > 1:
            result += str(nums[length - 1])
        if length > 2:
            result += ')'
        return result
