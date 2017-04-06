public class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int maxHere = nums[0];
        int minHere = nums[0];
        int maxSoFar = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int num = nums[i];
            maxHere *= num;
            minHere *= num;
            int tempMaxHere = Math.max(Math.max(maxHere, minHere), num);
            minHere = Math.min(Math.min(maxHere, minHere), num);
            maxHere = tempMaxHere;
            maxSoFar = Math.max(maxHere, maxSoFar);
        }
        return maxSoFar;
    }
}