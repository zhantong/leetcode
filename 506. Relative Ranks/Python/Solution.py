class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        map = [0] * (max(nums) + 1)
        for index, num in enumerate(nums):
            map[num] = index + 1
        result = [None] * len(nums)
        rank = 1
        for i in range(len(map) - 1, -1, -1):
            index = map[i]
            if index:
                value = None
                if rank == 1:
                    value = 'Gold Medal'
                elif rank == 2:
                    value = 'Silver Medal'
                elif rank == 3:
                    value = 'Bronze Medal'
                else:
                    value = str(rank)
                result[index - 1] = value
                rank += 1
        return result
