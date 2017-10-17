class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(32):
            base = 1 << i
            count_one = 0
            for num in nums:
                if base & num:
                    count_one += 1
            result += count_one * (len(nums) - count_one)
        return result
