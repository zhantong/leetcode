class Solution {
public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        struct Compare {
            bool operator()(vector<int> &v1, vector<int> &v2) {
                return v1[0] > v2[0];
            }
        };
        if (heightMap.size() == 0) {
            return 0;
        }
        priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
        int m = heightMap.size();
        int n = heightMap[0].size();
        for (int i = 0; i < m; i++) {
            heap.push(vector<int> {heightMap[i][0], i, 0});
            heightMap[i][0] *= -1;
            heightMap[i][0] -= 1;
            heap.push(vector<int> {heightMap[i][n - 1], i, n - 1});
            heightMap[i][n - 1] *= -1;
            heightMap[i][n - 1] -= 1;
        }
        for (int j = 1; j < n - 1; j++) {
            heap.push(vector<int> {heightMap[0][j], 0, j});
            heightMap[0][j] *= -1;
            heightMap[0][j] -= 1;
            heap.push(vector<int> {heightMap[m - 1][j], m - 1, j});
            heightMap[m - 1][j] *= -1;
            heightMap[m - 1][j] -= 1;
        }
        vector<vector<int>> steps{{-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1}};
        int result = 0;
        while (!heap.empty()) {
            vector<int> item = heap.top();
            heap.pop();
            for (auto &step : steps) {
                int row = item[1] + step[0];
                int col = item[2] + step[1];
                if (row >= 0 && col >= 0 && row < m && col < n && heightMap[row][col] >= 0) {
                    result += max(0, item[0] - heightMap[row][col]);
                    heap.push(vector<int> {max(item[0], heightMap[row][col]), row, col});
                    heightMap[row][col] *= -1;
                    heightMap[row][col] -= 1;
                }
            }
        }
        return result;
    }
};