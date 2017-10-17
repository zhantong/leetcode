class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if k < 1 or t < 0:
            return False
        buckets = {}
        for i, num in enumerate(nums):
            adjusted_num = num + 0x80000000
            bucket = adjusted_num // (t + 1)
            if bucket in buckets \
                    or (bucket - 1 in buckets and abs(adjusted_num - buckets[bucket - 1]) <= t) \
                    or (bucket + 1 in buckets and abs(adjusted_num - buckets[bucket + 1]) <= t):
                return True
            buckets[bucket] = adjusted_num
            if i >= k:
                del buckets[(nums[i - k] + 0x80000000) // (t + 1)]
        return False
