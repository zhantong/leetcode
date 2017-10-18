class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        unordered_set<string> got;
        int sumUp = 0;
        for (auto &rectangle : rectangles) {
            int a1 = rectangle[0];
            int b1 = rectangle[1];
            int a2 = rectangle[2];
            int b2 = rectangle[3];
            x1 = min(x1, a1);
            y1 = min(y1, b1);
            x2 = max(x2, a2);
            y2 = max(y2, b2);
            sumUp += (a2 - a1) * (b2 - b1);
            for (int i = 0; i < 3; i += 2) {
                for (int j = 1; j < 4; j += 2) {
                    string key = to_string(rectangle[i]) + " " + to_string(rectangle[j]);
                    if (got.find(key) != got.end()) {
                        got.erase(key);
                    } else {
                        got.insert(key);
                    }
                }
            }
        }
        return got.size() == 4
               && got.find(to_string(x1) + " " + to_string(y1)) != got.end()
               && got.find(to_string(x1) + " " + to_string(y2)) != got.end()
               && got.find(to_string(x2) + " " + to_string(y1)) != got.end()
               && got.find(to_string(x2) + " " + to_string(y2)) != got.end()
               && sumUp == (x2 - x1) * (y2 - y1);
    }
};