class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        class Utils {
        public:
            void rot(vector<int> &nums, int start, int end) {
                while (start < end) {
                    int temp = nums[start];
                    nums[start] = nums[end];
                    nums[end] = temp;
                    start++;
                    end--;
                }
            }
        };
        if (k == 0) {
            return;
        }
        if (k > nums.size()) {
            k %= nums.size();
        }
        Utils utils;
        utils.rot(nums, 0, nums.size() - 1);
        utils.rot(nums, 0, k - 1);
        utils.rot(nums, k, nums.size() - 1);
    }
};