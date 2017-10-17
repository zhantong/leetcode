public class Solution {
    public int splitArray(int[] nums, int m) {
        class Utils {
            boolean cut(int[] nums, int mid, int m) {
                int count = 1;
                int currentSum = 0;
                for (int num : nums) {
                    currentSum += num;
                    if (currentSum > mid) {
                        count++;
                        currentSum = num;
                        if (count > m) {
                            return false;
                        }
                    }
                }
                return true;
            }
        }
        int low = 0;
        int high = 0;
        for (int num : nums) {
            low = Math.max(low, num);
            high += num;
        }
        Utils utils = new Utils();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (utils.cut(nums, mid, m)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}