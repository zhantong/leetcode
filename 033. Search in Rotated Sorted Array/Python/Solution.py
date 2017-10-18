class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length = len(nums)
        low = 0
        high = length - 1
        while low < high:
            mid = (low + high) // 2
            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
        rotate = low
        low = 0
        high = length - 1
        while low <= high:
            mid = (low + high) // 2
            real_mid = (mid + rotate) % length
            if nums[real_mid] == target:
                return real_mid
            if nums[real_mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1
