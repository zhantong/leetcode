class Solution:
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        nums_length = len(nums)
        lengths = [1] * nums_length
        counts = [1] * nums_length
        for i in range(nums_length):
            for j in range(i):
                if nums[i] > nums[j]:
                    if lengths[i] == lengths[j] + 1:
                        counts[i] += counts[j]
                    elif lengths[i] < lengths[j] + 1:
                        lengths[i] = lengths[j] + 1
                        counts[i] = counts[j]
        max_length = max(lengths)
        result = 0
        for i in range(nums_length):
            if lengths[i] == max_length:
                result += counts[i]
        return result
