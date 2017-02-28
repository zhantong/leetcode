class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        int result = duration;
        int gain;
        for (int i = 1; i < timeSeries.size(); i++) {
            result += duration;
            gain = duration - (timeSeries[i] - timeSeries[i - 1]);
            if (gain > 0) {
                result -= gain;
            }
        }
        return result;
    }
};