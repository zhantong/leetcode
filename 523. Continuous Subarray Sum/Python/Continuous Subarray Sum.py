class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        memory = {}
        memory[0] = -1
        current_sum = 0
        for i in range(len(nums)):
            current_sum += nums[i]
            if k:
                current_sum %= k
            if current_sum in memory:
                if i - memory[current_sum] > 1:
                    return True
            else:
                memory[current_sum] = i
        return False
