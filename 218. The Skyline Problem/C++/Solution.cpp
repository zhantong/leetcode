class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        class Utils {
        public:
            vector<pair<int, int>> merge(vector<vector<int>> &buildings, int low, int high) {
                vector<pair<int, int>> result;
                if (low == high) {
                    result.push_back(pair<int, int>(buildings[low][0], buildings[low][2]));
                    result.push_back(pair<int, int>(buildings[low][1], 0));
                } else if (low < high) {
                    int mid = (low + high) / 2;
                    vector<pair<int, int>> lefts = merge(buildings, low, mid);
                    vector<pair<int, int>> rights = merge(buildings, mid + 1, high);
                    int heightLeft = 0;
                    int heightRight = 0;
                    while (!lefts.empty() || !rights.empty()) {
                        long currentLeft = lefts.empty() ? LONG_MAX : lefts.front().first;
                        long currentRight = rights.empty() ? LONG_MAX : rights.front().first;
                        long current = 0;
                        if (currentLeft < currentRight) {
                            current = lefts.front().first;
                            heightLeft = lefts.front().second;
                            lefts.erase(lefts.begin());
                        } else if (currentLeft > currentRight) {
                            current = rights.front().first;
                            heightRight = rights.front().second;
                            rights.erase(rights.begin());
                        } else {
                            current = lefts.front().first;
                            heightLeft = lefts.front().second;
                            heightRight = rights.front().second;
                            lefts.erase(lefts.begin());
                            rights.erase(rights.begin());
                        }
                        int height = max(heightLeft, heightRight);
                        if (result.empty() || result.back().second != height) {
                            result.push_back(pair<int, int>(current, height));
                        }
                    }
                }
                return result;
            }
        };
        Utils utils;
        return utils.merge(buildings, 0, buildings.size() - 1);
    }
};