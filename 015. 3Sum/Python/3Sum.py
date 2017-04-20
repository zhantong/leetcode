class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for i in range(len(nums) - 2):
            if i == 0 or nums[i] > nums[i - 1]:
                low = i + 1
                high = len(nums) - 1
                target = -nums[i]
                while low < high:
                    if nums[low] + nums[high] == target:
                        result.append([nums[i], nums[low], nums[high]])
                        while low < high and nums[low] == nums[low + 1]:
                            low += 1
                        low += 1
                        while low < high and nums[high] == nums[high - 1]:
                            high -= 1
                        high -= 1
                    elif nums[low] + nums[high] > target:
                        high -= 1
                    else:
                        low += 1
        return result
