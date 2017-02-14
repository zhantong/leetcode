public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) {
            return 0;
        }
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            int gain = prices[i] - prices[i - 1];
            if (gain > 0) {
                profit += gain;
            }
        }
        return profit;
    }
}