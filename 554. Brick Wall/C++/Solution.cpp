class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> count;
        for (auto &row : wall) {
            int current = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                current += row[i];
                if (count.find(current) == count.end()) {
                    count[current] = 0;
                }
                count[current]++;
            }
        }
        int maxValue = 0;
        for (auto &value : count) {
            maxValue = max(maxValue, value.second);
        }
        return wall.size() - maxValue;
    }
};