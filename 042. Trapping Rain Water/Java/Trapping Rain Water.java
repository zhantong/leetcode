public class Solution {
    public int trap(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int currentMaxLeft = 0;
        int currentMaxRight = 0;
        int result = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                currentMaxLeft = Math.max(currentMaxLeft, height[left]);
                result += currentMaxLeft - height[left];
                left++;
            } else {
                currentMaxRight = Math.max(currentMaxRight, height[right]);
                result += currentMaxRight - height[right];
                right--;
            }
        }
        return result;
    }
}