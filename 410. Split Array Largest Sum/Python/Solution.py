class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def cut(nums, mid, m):
            count = 1
            current_sum = 0
            for num in nums:
                current_sum += num
                if current_sum > mid:
                    count += 1
                    current_sum = num
                    if count > m:
                        return False
            return True

        low = max(nums)
        high = sum(nums)
        while low <= high:
            mid = (low + high) // 2
            cuts = cut(nums, mid, m)
            if cuts:
                high = mid - 1
            else:
                low = mid + 1
        return low
