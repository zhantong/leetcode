class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        for i, num in enumerate(nums):
            j = i + 1
            k = len(nums) - 1
            while j < k:
                current = nums[i] + nums[j] + nums[k]
                if current == target:
                    return current
                if abs(current - target) < abs(result - target):
                    result = current
                if current > target:
                    k -= 1
                else:
                    j += 1
        return result
