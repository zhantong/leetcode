class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def kth_largest(nums, start, end, k):
            pivot = nums[end]
            left = start
            for i in range(start, end):
                if nums[i] <= pivot:
                    nums[left], nums[i] = nums[i], nums[left]
                    left += 1
            nums[left], nums[end] = nums[end], nums[left]
            if left == k:
                return nums[left]
            elif left < k:
                return kth_largest(nums, left + 1, end, k)
            else:
                return kth_largest(nums, start, left - 1, k)

        return kth_largest(nums, 0, len(nums) - 1, len(nums) - k)
