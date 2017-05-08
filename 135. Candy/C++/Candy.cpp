class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> counts(length, 1);
        for (int i = 1; i < length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                counts[i] = counts[i - 1] + 1;
            }
        }
        for (int i = length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                counts[i] = max(counts[i], counts[i + 1] + 1);
            }
        }
        int result = 0;
        for (auto count : counts) {
            result += count;
        }
        return result;
    }
};