public class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] results = new int[target + 1];
        results[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    results[i] += results[i - num];
                }
            }
        }
        return results[target];
    }
}