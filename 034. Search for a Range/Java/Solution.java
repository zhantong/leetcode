public class Solution {
    public int[] searchRange(int[] nums, int target) {
        class Utils {
            int search(int[] nums, int target) {
                int low = 0;
                int high = nums.length - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (nums[mid] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return low;
            }
        }
        if (nums.length == 0) {
            return new int[] {-1, -1};
        }
        Utils utils = new Utils();
        int low = utils.search(nums, target);
        int high = utils.search(nums, target + 1);
        high--;
        if (low < nums.length && nums[low] == target) {
            return new int[] {low, high};
        }
        return new int[] {-1, -1};
    }
}