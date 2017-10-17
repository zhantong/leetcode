public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int[][] dp = new int[nums.length][nums.length];
        for (int j = 0; j < nums.length; j++) {
            int currentSum = 0;
            for (int i = j; i >= 0; i--) {
                currentSum += nums[i];
                if (i == j) {
                    dp[i][j] = nums[i];
                } else {
                    dp[i][j] = Math.max(currentSum - dp[i][j - 1], currentSum - dp[i + 1][j]);
                }
            }
        }
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return 2 * dp[0][nums.length - 1] >= sum;
    }
}