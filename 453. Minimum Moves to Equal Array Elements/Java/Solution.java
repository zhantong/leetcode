public class Solution {
    public int minMoves(int[] nums) {
        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int num : nums) {
            sum += num;
            if (num < min) {
                min = num;
            }
        }
        return sum - min * nums.length;
    }
}