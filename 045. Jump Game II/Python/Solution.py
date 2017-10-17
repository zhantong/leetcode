class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        index = 0
        current = 0
        next = 0
        while current < len(nums) - 1:
            result += 1
            while index <= current:
                next = max(next, index + nums[index])
                index += 1
            current = next
        return result
