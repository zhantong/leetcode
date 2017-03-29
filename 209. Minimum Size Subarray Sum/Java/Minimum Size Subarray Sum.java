public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int i = 0;
        int theSum = 0;
        int theMin = Integer.MAX_VALUE;
        for (int j = 0; j < nums.length; j++) {
            theSum += nums[j];
            while (theSum >= s) {
                theMin = Math.min(theMin, j - i + 1);
                if (theMin == 1) {
                    return theMin;
                }
                theSum -= nums[i];
                i++;
            }
        }
        return theMin == Integer.MAX_VALUE ? 0 : theMin;
    }
}