class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.insert(0, 1)
        nums.append(1)
        length = len(nums)
        dp = [[0] * length for i in range(length)]
        for gap in range(2, length):
            for left in range(length - gap):
                right = left + gap
                for i in range(left + 1, right):
                    dp[left][right] = max(dp[left][right],
                                          nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right])
        return dp[0][-1]
