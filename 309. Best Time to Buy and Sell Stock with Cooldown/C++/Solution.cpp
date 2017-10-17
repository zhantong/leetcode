class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> buy(prices.size());
        vector<int> sell(prices.size());
        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (i == 1) {
                buy[i] = max(buy[i - 1], -prices[i]);
            } else {
                buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            }
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[prices.size() - 1];
    }
};