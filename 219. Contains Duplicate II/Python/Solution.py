class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        window = set()
        for i in range(0, len(nums)):
            if i > k:
                window.remove(nums[i - k - 1])
            if nums[i] in window:
                return True
            window.add(nums[i])
        return False
