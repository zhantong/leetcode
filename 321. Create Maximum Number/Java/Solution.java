public class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        class Utils {
            int[] maxNumberLengthK(int[] nums, int k) {
                int[] result = new int[k];
                int index = 0;
                int length = nums.length;
                for (int i = 0; i < length; i++) {
                    while (index > 0 && result[index - 1] < nums[i] && length - i >= k - (index - 1)) {
                        index--;
                    }
                    if (index < k) {
                        result[index] = nums[i];
                        index++;
                    }
                }
                return result;
            }

            int[] merge(int[] nums1, int[] nums2) {
                int[] result = new int[nums1.length + nums2.length];
                int i = 0;
                int j = 0;
                int index = 0;
                while (i < nums1.length && j < nums2.length) {
                    if (greater(nums1, i, nums2, j)) {
                        result[index] = nums1[i];
                        i++;
                        index++;
                    } else {
                        result[index] = nums2[j];
                        j++;
                        index++;
                    }
                }
                if (i == nums1.length) {
                    while (j < nums2.length) {
                        result[index] = nums2[j];
                        j++;
                        index++;
                    }
                } else {
                    while (i < nums1.length) {
                        result[index] = nums1[i];
                        i++;
                        index++;
                    }
                }
                return result;
            }

            boolean greater(int[] nums1, int start1, int[] nums2, int start2) {
                while (start1 < nums1.length && start2 < nums2.length && nums1[start1] == nums2[start2]) {
                    start1++;
                    start2++;
                }
                if (start1 == nums1.length && start2 == nums2.length) {
                    return true;
                }
                if (start1 == nums1.length) {
                    return false;
                }
                if (start2 == nums2.length) {
                    return true;
                }
                return nums1[start1] > nums2[start2];
            }
        }
        Utils utils = new Utils();
        int[] result = new int[k];
        for (int i = 0; i <= k; i++) {
            if (i <= nums1.length && k - i <= nums2.length) {
                int[] current = utils.merge(utils.maxNumberLengthK(nums1, i), utils.maxNumberLengthK(nums2, k - i));
                if (utils.greater(current, 0, result, 0)) {
                    result = current;
                }
            }
        }
        return result;
    }
}