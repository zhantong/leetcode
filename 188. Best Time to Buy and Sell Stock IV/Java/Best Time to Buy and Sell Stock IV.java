public class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        if (k >= prices.length / 2) {
            int result = 0;
            for (int i = 1; i < prices.length; i++) {
                if (prices[i] > prices[i - 1]) {
                    result += prices[i] - prices[i - 1];
                }
            }
            return result;
        }
        int[] dp = new int[prices.length];
        for (int time = 0; time < k; time++) {
            int current = dp[0] - prices[0];
            for (int i = 1; i < prices.length; i++) {
                current = Math.max(current, dp[i] - prices[i]);
                dp[i] = Math.max(dp[i - 1], prices[i] + current);

            }
        }
        int max = dp[0];
        for (int num : dp) {
            if (max < num) {
                max = num;
            }
        }
        return max;
    }
}