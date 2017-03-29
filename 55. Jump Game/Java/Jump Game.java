public class Solution {
    public boolean canJump(int[] nums) {
        int current = 0;
        int i = 0;
        while (i < nums.length && i <= current) {
            current = Math.max(current, i + nums[i]);
            i++;
        }
        return i == nums.length;
    }
}