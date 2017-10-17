public class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int result = 0;
        int i = 0;
        int j = nums.length - 1;
        while (i < j) {
            result += nums[j] - nums[i];
            i++;
            j--;
        }
        return result;
    }
}