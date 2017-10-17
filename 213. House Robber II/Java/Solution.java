public class Solution {
    public int rob(int[] nums) {
        class Utils {
            int robber(int[] nums, int start, int end) {
                if (start >= end) {
                    return 0;
                }
                int[] dp = new int[end];
                dp[start] = nums[start];
                for (int i = start + 1; i < end; i++) {
                    dp[i] = Math.max(nums[i] + (i > 1 ? dp[i - 2] : 0), dp[i - 1]);
                }
                return dp[end - 1];
            }
        }
        if (nums.length == 1) {
            return nums[0];
        }
        Utils utils = new Utils();
        return Math.max(utils.robber(nums, 0, nums.length - 1), utils.robber(nums, 1, nums.length));
    }
}