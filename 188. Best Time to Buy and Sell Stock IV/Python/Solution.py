class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        if k >= len(prices) // 2:
            result = 0
            for i in range(1, len(prices)):
                if prices[i] > prices[i - 1]:
                    result += prices[i] - prices[i - 1]
            return result
        dp = [0] * len(prices)
        for time in range(k):
            current = dp[0] - prices[0]
            for i in range(1, len(prices)):
                current = max(current, dp[i] - prices[i])
                dp[i] = max(dp[i - 1], prices[i] + current)
        return max(dp)
