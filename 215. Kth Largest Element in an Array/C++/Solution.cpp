class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        class Utils {
        public:
            int kthLargest(vector<int> &nums, int start, int end, int k) {
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

            void swap(vector<int> &nums, int i, int j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        };
        Utils utils;
        return utils.kthLargest(nums, 0, nums.size() - 1, nums.size() - k);
    }
};