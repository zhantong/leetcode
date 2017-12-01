class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int result = 0;
        for (auto &pointA : points) {
            map<int, int> distances;
            for (auto &pointB : points) {
                int distance = (pointA.first - pointB.first) * (pointA.first - pointB.first) +
                               (pointA.second - pointB.second) * (pointA.second - pointB.second);
                distances[distance]++;
            }
            for (auto &item : distances) {
                result += item.second * (item.second - 1);
            }
        }
        return result;
    }
};