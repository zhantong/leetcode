class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        def predict(nums, start, end, first, second):
            if start > end:
                return first >= second
            return not predict(nums, start + 1, end, second, first + nums[start]) \
                or not predict(nums, start, end - 1, second, first + nums[end])

        if len(nums) <= 1:
            return True
        return predict(nums, 0, len(nums) - 1, 0, 0)
