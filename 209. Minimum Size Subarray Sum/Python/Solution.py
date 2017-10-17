class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        the_sum = 0
        the_min = sys.maxsize
        for j, num in enumerate(nums):
            the_sum += num
            while the_sum >= s:
                the_min = min(the_min, j - i + 1)
                if the_min == 1:
                    return the_min
                the_sum -= nums[i]
                i += 1
        return 0 if the_min == sys.maxsize else the_min
