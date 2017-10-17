public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        int[][] dp = new int[3][prices.length];
        for (int time = 1; time < 3; time++) {
            int current = dp[time - 1][0] - prices[0];
            for (int i = 1; i < prices.length; i++) {
                dp[time][i] = Math.max(dp[time][i - 1], prices[i] + current);
                current = Math.max(current, dp[time - 1][i] - prices[i]);
            }
        }
        int[] last = dp[dp.length - 1];
        int max = last[0];
        for (int num : last) {
            if (max < num) {
                max = num;
            }
        }
        return max;
    }
}