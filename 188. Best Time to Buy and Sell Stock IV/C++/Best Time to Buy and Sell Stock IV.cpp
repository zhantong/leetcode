class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        if (k >= prices.size() / 2) {
            int result = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    result += prices[i] - prices[i - 1];
                }
            }
            return result;
        } else {
            vector<int> dp(prices.size(), 0);
            for (int time = 0; time < k; time++) {
                int current = dp[0] - prices[0];
                for (int i = 1; i < prices.size(); i++) {
                    current = max(current, dp[i] - prices[i]);
                    dp[i] = max(dp[i - 1], prices[i] + current);
                }
            }
            return *max_element(dp.begin(), dp.end());
        }
    }
};