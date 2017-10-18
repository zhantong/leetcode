class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        if S > 1000:
            return 0
        memory = {}
        memory[nums[0]] = 1
        memory[-nums[0]] = 1 if nums[0] != 0 else 2
        for num in nums[1:]:
            new_memory = {}
            for key, value in memory.items():
                if key + num not in new_memory:
                    new_memory[key + num] = 0
                new_memory[key + num] += value
                if key - num not in new_memory:
                    new_memory[key - num] = 0
                new_memory[key - num] += value
            memory = new_memory
        if S not in memory:
            return 0
        return memory[S]
