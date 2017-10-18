class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        if not nums:
            return False
        low = 0
        high = len(nums) - 1
        while low < high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return True
            if nums[mid] > nums[high]:
                if nums[low] <= target < nums[mid]:
                    high = mid
                else:
                    low = mid + 1
            elif nums[mid] < nums[high]:
                if nums[mid] < target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid
            else:
                high -= 1
        return nums[low] == target
