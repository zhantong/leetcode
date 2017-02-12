class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_count = 0
        count = 0
        for num in nums:
            if num == 0:
                if count > max_count:
                    max_count = count
                count = 0
            elif num == 1:
                count += 1
        if count > max_count:
            max_count = count
        return max_count
