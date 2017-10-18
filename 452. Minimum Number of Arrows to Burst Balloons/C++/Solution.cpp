class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>> &points) {
        sort(points.begin(), points.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });
        long currentStart = LONG_MIN;
        int result = 0;
        for (auto &point : points) {
            if (point.first > currentStart) {
                currentStart = point.second;
                result += 1;
            }
        }
        return result;
    }
};