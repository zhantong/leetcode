class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_set = set(nums)
        result = 0
        for num in nums:
            if num in nums_set:
                current = num
                count = 1
                while current - 1 in nums_set:
                    nums_set.remove(current - 1)
                    current -= 1
                    count += 1
                current = num
                while current + 1 in nums_set:
                    nums_set.remove(current + 1)
                    current += 1
                    count += 1
                result = max(result, count)
        return result
