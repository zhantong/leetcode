public class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        int j = 1;
        while (j < nums.length) {
            if (nums[i] != nums[j]) {
                if ((i + 1) == j) {
                    i++;
                    j++;
                } else {
                    nums[i + 1] = nums[j];
                    i++;
                    j++;
                }
            } else {
                j++;
            }
        }
        return nums.length == 0 ? i : (i + 1);
    }
}