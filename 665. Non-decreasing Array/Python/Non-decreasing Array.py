class Solution:
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        is_modified = False
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                if is_modified:
                    return False
                is_modified = True
                if i < 2 or nums[i - 2] <= nums[i]:
                    nums[i - 1] = nums[i]
                else:
                    nums[i] = nums[i - 1]
        return True
