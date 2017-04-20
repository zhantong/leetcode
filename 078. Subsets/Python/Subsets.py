class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        for i in range(1 << len(nums)):
            current = []
            for j in range(len(nums)):
                if i & 1 << j:
                    current.append(nums[j])
            result.append(current)
        return result
