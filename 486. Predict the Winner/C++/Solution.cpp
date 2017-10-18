class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for (int j = 0; j < nums.size(); j++) {
            int currentSum = 0;
            for (int i = j; i >= 0; i--) {
                currentSum += nums[i];
                if (i == j) {
                    dp[i][j] = nums[i];
                } else {
                    dp[i][j] = max(currentSum - dp[i][j - 1], currentSum - dp[i + 1][j]);
                }
            }
        }
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        return 2 * dp[0][nums.size() - 1] >= sum;
    }
};