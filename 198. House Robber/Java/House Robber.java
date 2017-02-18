public class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] results = new int[nums.length + 1];
        results[0] = 0;
        results[1] = nums[0];
        for (int i = 2; i <= nums.length; i++) {
            results[i] = Math.max(nums[i - 1] + results[i - 2], results[i - 1]);
        }
        return results[nums.length];
    }
}