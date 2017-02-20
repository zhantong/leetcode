class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        j = 1
        length = len(nums)
        while j < length:
            if nums[i] != nums[j]:
                if (i + 1) == j:
                    i += 1
                    j += 1
                else:
                    nums[i + 1] = nums[j]
                    i += 1
                    j += 1
            else:
                j += 1
        return i if len(nums) == 0 else i + 1
