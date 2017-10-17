public class Solution {
    public int findKthLargest(int[] nums, int k) {
        class Utils {
            int kthLargest(int[] nums, int start, int end, int k) {
                int pivot = nums[end];
                int left = start;
                for (int i = start; i < end; i++) {
                    if (nums[i] <= pivot) {
                        swap(nums, left++, i);
                    }
                }
                swap(nums, left, end);
                if (left == k) {
                    return nums[left];
                } else if (left < k) {
                    return kthLargest(nums, left + 1, end, k);
                } else {
                    return kthLargest(nums, start, left - 1, k);
                }
            }

            void swap(int[] nums, int i, int j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        Utils utils = new Utils();
        return utils.kthLargest(nums, 0, nums.length - 1, nums.length - k);
    }
}