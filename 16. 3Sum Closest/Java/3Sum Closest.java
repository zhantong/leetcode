public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length - 2; i++) {
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                int current = nums[i] + nums[j] + nums[k];
                if (current == target) {
                    return current;
                }
                if (Math.abs(current - target) < Math.abs(result - target)) {
                    result = current;
                }
                if (current > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
}