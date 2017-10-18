class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        vector<int> dp(envelopes.size(), 0);
        int currentLength = 0;
        for (auto &envelope : envelopes) {
            int low = 0;
            int high = currentLength;
            int value = envelope.second;
            while (low < high) {
                int mid = (low + high) / 2;
                if (dp[mid] == value) {
                    low = mid;
                    break;
                }
                if (dp[mid] < value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            dp[low] = value;
            if (low == currentLength) {
                currentLength++;
            }
        }
        return currentLength;
    }
};