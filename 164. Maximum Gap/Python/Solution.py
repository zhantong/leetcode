class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums or len(nums) < 2:
            return 0
        the_min = min(nums)
        the_max = max(nums)
        gap = int(math.ceil((float(the_max) - the_min) / (len(nums) - 1)))
        bucket_min = [the_max + 1] * (len(nums) - 1)
        bucket_max = [the_min - 1] * (len(nums) - 1)
        for num in nums:
            if num == the_max or num == the_min:
                continue
            index = (num - the_min) // gap
            bucket_min[index] = min(num, bucket_min[index])
            bucket_max[index] = max(num, bucket_max[index])
        prev = the_min
        for current_min, current_max in zip(bucket_min, bucket_max):
            if current_min == the_max + 1:
                continue
            gap = max(gap, current_min - prev)
            prev = current_max
        gap = max(gap, the_max - prev)
        return gap
