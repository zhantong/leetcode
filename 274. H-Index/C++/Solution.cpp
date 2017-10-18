class Solution {
public:
    int hIndex(vector<int> &citations) {
        int length = citations.size();
        vector<int> counts(length + 1);
        for (const auto &citation : citations) {
            if (citation >= length) {
                counts[length]++;
            } else {
                counts[citation]++;
            }
        }
        int paperSum = 0;
        for (int i = counts.size() - 1; i >= 0; i--) {
            paperSum += counts[i];
            if (paperSum >= i) {
                return i;
            }
        }
        return 0;
    }
};