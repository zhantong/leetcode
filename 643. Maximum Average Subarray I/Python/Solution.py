class Solution:
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        i = 0
        sum = 0
        max_sum = -sys.maxsize
        for j in range(len(nums)):
            sum += nums[j]
            if j - i == k - 1:
                max_sum = max(max_sum, sum)
                sum -= nums[i]
                i += 1
        return max_sum / k
