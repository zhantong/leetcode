public class Solution {
    public int maxArea(int[] height) {
        int maxWater = 0;
        int low = 0;
        int high = height.length - 1;
        while (low < high) {
            int tall = Math.min(height[low], height[high]);
            maxWater = Math.max(maxWater, tall * (high - low));
            while (low < high && height[low] <= tall) {
                low++;
            }
            while (low < high && height[high] <= tall) {
                high--;
            }
        }
        return maxWater;
    }
}