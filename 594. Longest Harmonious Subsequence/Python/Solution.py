class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        memory = {}
        for num in nums:
            if num not in memory:
                memory[num] = 0
            memory[num] += 1
        result = 0
        for key, value in memory.items():
            if key + 1 in memory:
                result = max(result, value + memory[key + 1])
        return result
