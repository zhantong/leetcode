public class Solution {
    public int minPatches(int[] nums, int n) {
        int hope = 1;
        int result = 0;
        int index = 0;
        while (hope <= n) {
            if (index < nums.length && nums[index] <= hope) {
                hope += nums[index];
                index++;
            } else {
                result++;
                if (n - hope < hope) {
                    break;
                }
                hope += hope;
            }
        }
        return result;
    }
}