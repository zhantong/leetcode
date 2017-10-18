class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqCapital;
        priority_queue<int> pqProfit;
        for (int i = 0; i < Profits.size(); i++) {
            pqCapital.push(pair<int, int>(Capital[i], Profits[i]));
        }
        for (int i = 0; i < k; i++) {
            while (!pqCapital.empty() && pqCapital.top().first <= W) {
                pqProfit.push(pqCapital.top().second);
                pqCapital.pop();
            }
            if (pqProfit.empty()) {
                break;
            }
            W += pqProfit.top();
            pqProfit.pop();
        }
        return W;
    }
};