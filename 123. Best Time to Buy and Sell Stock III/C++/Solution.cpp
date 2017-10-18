class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int time = 1; time < 3; time++) {
            int current = dp[time - 1][0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                dp[time][i] = max(dp[time][i - 1], prices[i] + current);
                current = max(current, dp[time - 1][i] - prices[i]);
            }
        }
        vector<int> last = dp[dp.size() - 1];
        int max = last[0];
        for (int num : last) {
            if (max < num) {
                max = num;
            }
        }
        return max;
    }
};