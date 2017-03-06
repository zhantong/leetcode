class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        buy = [0] * len(prices)
        sell = [0] * len(prices)
        buy[0] = -prices[0]
        for i in range(1, len(prices)):
            if i == 1:
                buy[i] = max(buy[i - 1], -prices[i])
            else:
                buy[i] = max(buy[i - 1], sell[i - 2] - prices[i])
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i])
        return sell[len(prices) - 1]
