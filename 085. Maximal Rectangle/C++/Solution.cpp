class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        vector<int> heights(matrix[0].size(), 0);
        int result = 0;
        for (const auto &row : matrix) {
            for (int i = 0; i < row.size(); i++) {
                if (row[i] == '1') {
                    heights[i]++;
                } else {
                    heights[i] = 0;
                }
            }
            stack<int> sta;
            int i = 0;
            while (i < heights.size()) {
                while (!sta.empty() && heights[i] < heights[sta.top()]) {
                    int index = sta.top();
                    sta.pop();
                    int current = heights[index] * (i - (sta.empty() ? -1 : sta.top()) - 1);
                    result = max(result, current);
                }
                sta.push(i);
                i++;
            }
            while (!sta.empty()) {
                int index = sta.top();
                sta.pop();
                int current = heights[index] * (i - (sta.empty() ? -1 : sta.top()) - 1);
                result = max(result, current);
            }
        }
        return result;
    }
};