public class Solution {
    public int maximumGap(int[] nums) {
        if (nums.length < 2) {
            return 0;
        }
        int theMin = nums[0];
        int theMax = nums[0];
        for (int num : nums) {
            theMin = Math.min(theMin, num);
            theMax = Math.max(theMax, num);
        }
        int gap = (int) Math.ceil((double)(theMax - theMin) / (nums.length - 1));
        int[] bucketMin = new int[nums.length - 1];
        Arrays.fill(bucketMin, theMax + 1);
        int[] bucketMax = new int[nums.length - 1];
        Arrays.fill(bucketMax, theMin - 1);
        for (int num : nums) {
            if (num == theMax || num == theMin) {
                continue;
            }
            int index = (num - theMin) / gap;
            bucketMin[index] = Math.min(bucketMin[index], num);
            bucketMax[index] = Math.max(bucketMax[index], num);
        }
        int prev = theMin;
        for (int i = 0; i < bucketMax.length; i++) {
            if (bucketMin[i] == theMax + 1) {
                continue;
            }
            gap = Math.max(gap, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        gap = Math.max(gap, theMax - prev);
        return gap;
    }
}