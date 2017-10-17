class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        so_far = [None] * (len(nums) + 1)
        so_far[0] = 0
        memory = {}
        memory[0] = 0
        for i in range(1, len(nums) + 1):
            so_far[i] = so_far[i - 1] + (1 if nums[i - 1] == 1 else -1)
            if so_far[i] not in memory:
                memory[so_far[i]] = i
            else:
                result = max(result, i - memory[so_far[i]])
        return result
