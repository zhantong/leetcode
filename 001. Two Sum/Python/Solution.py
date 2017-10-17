class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        needs = {}
        for (index, num) in enumerate(nums):
            if num in needs:
                return [needs[num], index]
            needs[target - num] = index
