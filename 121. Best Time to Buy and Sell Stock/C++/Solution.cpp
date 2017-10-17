class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxEndingHere = 0;
        int maxSoFar = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxEndingHere = max(0, maxEndingHere + prices[i] - prices[i - 1]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};