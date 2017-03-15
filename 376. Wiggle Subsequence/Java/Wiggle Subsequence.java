public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }
        int i = 1;
        while (i < nums.length && nums[i] == nums[i - 1]) {
            i++;
        }
        if (i == nums.length) {
            return 1;
        }
        boolean isIncrease = nums[0] > nums[i];
        int result = 2;
        for (int j = i + 1; j < nums.length; j++) {
            if ((isIncrease && nums[j] > nums[j - 1]) || (!isIncrease && nums[j] < nums[j - 1])) {
                result++;
                isIncrease = !isIncrease;
            }
        }
        return result;
    }
}