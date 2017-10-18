class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        nums.sort()
        lengths = [1] * len(nums)
        childs = [None] * len(nums)
        max_length = 0
        max_length_index = -1
        for i in range(len(nums)):
            for j in range(i):
                if not nums[i] % nums[j] and lengths[i] <= lengths[j]:
                    lengths[i] = lengths[j] + 1
                    childs[i] = j
                    if lengths[i] > max_length:
                        max_length = lengths[i]
                        max_length_index = i
        result = []
        index = max_length_index
        while index is not None:
            result.append(nums[index])
            index = childs[index]
        return result
