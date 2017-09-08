class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int theMin = Integer.MAX_VALUE;
        int theMax = Integer.MIN_VALUE;
        boolean isUnsorted = false;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                theMax = Math.max(theMax, nums[i]);
                theMin = Math.min(theMin, nums[i + 1]);
                isUnsorted = true;
            }
        }
        if (!isUnsorted) {
            return 0;
        }
        int start = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > theMin) {
                start = i;
                break;
            }
        }
        int end = -1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] < theMax) {
                end = i;
                break;
            }
        }
        return end - start + 1;
    }
}