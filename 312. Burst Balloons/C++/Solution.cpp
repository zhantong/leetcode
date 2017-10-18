class Solution {
public:
    int maxCoins(vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int length = nums.size();
        vector<vector<int>> dp(length, vector<int>(length, 0));
        for (int gap = 2; gap < length; gap++) {
            for (int left = 0; left < length - gap; left++) {
                int right = left + gap;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right],
                                          nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][length - 1];
    }
};