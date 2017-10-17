public class Solution {
    public int maxCoins(int[] nums) {
        int[] newNums = new int[nums.length + 2];
        System.arraycopy(nums, 0, newNums, 1, nums.length);
        newNums[0] = 1;
        newNums[newNums.length - 1] = 1;
        int length = newNums.length;
        int[][] dp = new int[length][length];
        for (int gap = 2; gap < length; gap++) {
            for (int left = 0; left < length - gap; left++) {
                int right = left + gap;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = Math.max(dp[left][right], newNums[left] * newNums[i] * newNums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][dp.length - 1];
    }
}