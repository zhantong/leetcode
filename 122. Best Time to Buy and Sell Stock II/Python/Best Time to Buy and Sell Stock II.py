class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2:
            return 0
        profit = 0
        for i in range(1, len(prices)):
            gain = prices[i] - prices[i - 1]
            if gain > 0:
                profit += gain
        return profit
