class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int gain = prices[i] - prices[i - 1];
            if (gain > 0) {
                profit += gain;
            }
        }
        return profit;
    }
};