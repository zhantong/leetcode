class Solution {
    public int findNumberOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int numsLength = nums.length;
        int[] lengths = new int[numsLength];
        int[] counts = new int[numsLength];
        int maxLength = Integer.MIN_VALUE;
        for (int i = 0; i < numsLength; i++) {
            lengths[i] = 1;
            counts[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengths[i] == lengths[j] + 1) {
                        counts[i] += counts[j];
                    } else if (lengths[i] < lengths[j] + 1) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    }
                }
            }
            maxLength = Math.max(maxLength, lengths[i]);
        }
        int result = 0;
        for (int i = 0; i < numsLength; i++) {
            if (lengths[i] == maxLength) {
                result += counts[i];
            }
        }
        return result;
    }
}