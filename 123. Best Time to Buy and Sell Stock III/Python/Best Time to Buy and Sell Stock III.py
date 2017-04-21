class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        dp = [[0] * len(prices) for i in range(3)]
        for time in range(1, 3):
            current = dp[time - 1][0] - prices[0]
            for i in range(1, len(prices)):
                dp[time][i] = max(dp[time][i - 1], prices[i] + current)
                current = max(current, dp[time - 1][i] - prices[i])
        return max(dp[-1])
