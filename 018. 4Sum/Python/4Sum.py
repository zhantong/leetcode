class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for i in range(len(nums) - 3):
            if i == 0 or nums[i] > nums[i - 1]:
                for j in range(i + 1, len(nums) - 2):
                    if j == i + 1 or nums[j] > nums[j - 1]:
                        low = j + 1
                        high = len(nums) - 1
                        goal = target - nums[i] - nums[j]
                        while low < high:
                            if nums[low] + nums[high] == goal:
                                result.append([nums[i], nums[j], nums[low], nums[high]])
                                while low < high and nums[low] == nums[low + 1]:
                                    low += 1
                                while low < high and nums[high] == nums[high - 1]:
                                    high -= 1
                                high -= 1
                            elif nums[low] + nums[high] > goal:
                                high -= 1
                            else:
                                low += 1
        return result
