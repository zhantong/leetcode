class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        index = 1
        count = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] and count < 2:
                nums[index] = nums[i]
                index += 1
                count += 1
            elif nums[i] != nums[i - 1]:
                nums[index] = nums[i]
                index += 1
                count = 1
        return index
