class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        count = 0
        for num in nums:
            if num == 0:
                result = max(result, count)
                count = 0
            else:
                count += 1
        result = max(result, count)
        return result
