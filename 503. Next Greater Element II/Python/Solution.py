class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        stack = []
        for i in range(len(nums) - 1, -1, -1):
            stack.append(i)
        result = [None] * len(nums)
        for i in range(len(nums) - 1, -1, -1):
            while stack and nums[stack[-1]] <= nums[i]:
                stack.pop()
            if stack:
                result[i] = nums[stack[-1]]
            else:
                result[i] = -1
            stack.append(i)
        return result
