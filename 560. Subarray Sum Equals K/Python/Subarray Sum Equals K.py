class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sum = 0
        result = 0
        memory = {}
        memory[0] = 1
        for num in nums:
            sum += num
            if sum - k in memory:
                result += memory[sum - k]
            if sum not in memory:
                memory[sum] = 0
            memory[sum] += 1
        return result
