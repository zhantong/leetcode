class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        result = 0
        i = 0
        j = len(nums) - 1
        while i < j:
            result += nums[j] - nums[i]
            i += 1
            j -= 1
        return result
