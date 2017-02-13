public class Solution {
    public void moveZeroes(int[] nums) {
        int firstZeroIndex = 0;
        while (firstZeroIndex < nums.length && nums[firstZeroIndex] != 0) {
            firstZeroIndex++;
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0 && i > firstZeroIndex) {
                nums[firstZeroIndex] = nums[i];
                nums[i] = 0;
                firstZeroIndex++;
            }
        }
    }
}