class Solution {
public:
    int rob(vector<int> &nums) {
        class Utils {
        public:
            int robber(vector<int> &nums, int start, int end) {
                if (start >= end) {
                    return 0;
                }
                vector<int> dp(end, 0);
                dp[start] = nums[start];
                for (int i = start + 1; i < end; i++) {
                    dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), dp[i - 1]);
                }
                return dp[end - 1];
            }
        };
        if (nums.size() == 1) {
            return nums[0];
        }
        Utils utils;
        return max(utils.robber(nums, 0, nums.size() - 1), utils.robber(nums, 1, nums.size()));
    }
};