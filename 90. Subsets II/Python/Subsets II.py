class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        def subsets(nums, result, current, start):
            result.append(current[:])
            for i in range(start, len(nums)):
                if i == start or nums[i] != nums[i - 1]:
                    current.append(nums[i])
                    subsets(nums, result, current, i + 1)
                    current.pop()

        nums.sort()
        result = []
        subsets(nums, result, [], 0)
        return result
