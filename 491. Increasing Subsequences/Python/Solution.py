class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def subsequences(nums, result, current, start):
            if len(current) >= 2:
                result.add(tuple(current[:]))
            for i in range(start, len(nums)):
                if not current or current[-1] <= nums[i]:
                    current.append(nums[i])
                    subsequences(nums, result, current, i + 1)
                    current.pop()

        result = set()
        subsequences(nums, result, [], 0)
        return [list(item) for item in result]
