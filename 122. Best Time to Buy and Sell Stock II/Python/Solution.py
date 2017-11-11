class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        for i in range(1, len(prices)):
            gain = prices[i] - prices[i - 1]
            if gain > 0:
                profit += gain
        return profit
