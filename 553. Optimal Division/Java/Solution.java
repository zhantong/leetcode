public class Solution {
    public String optimalDivision(int[] nums) {
        int length = nums.length;
        StringBuilder builder = new StringBuilder();
        if (length > 0) {
            builder.append(nums[0]);
        }
        if (length > 1) {
            builder.append('/');
        }
        if (length > 2) {
            builder.append('(');
        }
        for (int i = 1; i < length - 1; i++) {
            builder.append(nums[i]);
            builder.append('/');
        }
        if (length > 1) {
            builder.append(nums[length - 1]);
        }
        if (length > 2) {
            builder.append(')');
        }
        return builder.toString();
    }
}