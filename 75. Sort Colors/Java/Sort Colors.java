public class Solution {
    public void sortColors(int[] nums) {
        int left = 0;
        while (left < nums.length && nums[left] == 0) {
            left++;
        }
        int right = nums.length - 1;
        while (right >= 0 && nums[right] == 2) {
            right--;
        }
        int current = left;
        while (current <= right && left <= right) {
            if (nums[current] == 0) {
                if (current == left) {
                    current++;
                } else {
                    int temp = nums[left];
                    nums[left] = nums[current];
                    nums[current] = temp;
                }
                left++;
            } else if (nums[current] == 2) {
                if (current == right) {
                    current++;
                } else {
                    int temp = nums[right];
                    nums[right] = nums[current];
                    nums[current] = temp;
                }
                right--;
            } else {
                current++;
            }
        }
    }
}