public class Solution {
    public void rotate(int[] nums, int k) {
        class Utils {
            public void rot(int[] nums, int start, int end) {
                while (start < end) {
                    int temp = nums[start];
                    nums[start] = nums[end];
                    nums[end] = temp;
                    start++;
                    end--;
                }
            }
        }
        if (k == 0) {
            return;
        }
        if (k > nums.length) {
            k %= nums.length;
        }
        Utils utils = new Utils();
        utils.rot(nums, 0, nums.length - 1);
        utils.rot(nums, 0, k - 1);
        utils.rot(nums, k, nums.length - 1);
    }
}