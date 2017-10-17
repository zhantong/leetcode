class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_ending_here = 0
        max_so_far = 0
        for i in range(1, len(prices)):
            max_ending_here = max(0, max_ending_here + (prices[i] - prices[i - 1]))
            max_so_far = max(max_so_far, max_ending_here)
        return max_so_far
