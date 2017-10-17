public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int i = 0;
        long sum = 0;
        long maxSum = Long.MIN_VALUE;
        for (int j = 0; j < nums.length; j++) {
            sum += nums[j];
            if (j - i == k - 1) {
                maxSum = Math.max(maxSum, sum);
                sum -= nums[i];
                i++;
            }
        }
        return (double) maxSum / k;
    }
}