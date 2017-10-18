class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int target = 0;
        for (auto &num : nums) {
            target += num;
        }
        if (target % 2 == 1) {
            return false;
        }
        target /= 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1));
        dp[0][0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][target];
    }
};