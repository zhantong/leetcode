public class Solution {
    public boolean search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            while (low < high && nums[low] == nums[high]) {
                low++;
            }
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] >= nums[low]) {
                if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    if (nums[low] > target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            } else {
                if (nums[mid] > target) {
                    high = mid - 1;
                } else {
                    if (nums[high] < target) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }
}