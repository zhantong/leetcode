class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        vector<int> buckets(1440, 0);
        for (auto &point : timePoints) {
            int minutes = stoi(point.substr(0, 2)) * 60 + stoi(point.substr(3));
            buckets[minutes]++;
            if (buckets[minutes] > 1) {
                return 0;
            }
        }
        int result = INT_MAX;
        int prev = -1440;
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i] != 0) {
                result = min(result, i - prev);
                prev = i;
            }
        }
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i] != 0) {
                result = min(result, 1440 + i - prev);
                break;
            }
        }
        return result;
    }
};