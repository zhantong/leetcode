class Solution {
public:
    int trapRainWater(vector <vector<int>> &heightMap) {
        if (heightMap.size() == 0) {
            return 0;
        }
        priority_queue < pair < int, int >, vector < pair < int, int >>, greater < pair < int, int >> > heap;
        int m = heightMap.size();
        int n = heightMap[0].size();
        for (int i = 0; i < m; i++) {
            heap.push(pair<int, int>(heightMap[i][0], i << 8));
            heightMap[i][0] *= -1;
            heightMap[i][0] -= 1;
            heap.push(pair<int, int>(heightMap[i][n - 1], (i << 8) | (n - 1)));
            heightMap[i][n - 1] *= -1;
            heightMap[i][n - 1] -= 1;
        }
        for (int j = 1; j < n - 1; j++) {
            heap.push(pair<int, int>(heightMap[0][j], j));
            heightMap[0][j] *= -1;
            heightMap[0][j] -= 1;
            heap.push(pair<int, int>(heightMap[m - 1][j], ((m - 1) << 8) | j));
            heightMap[m - 1][j] *= -1;
            heightMap[m - 1][j] -= 1;
        }
        vector <vector<int>> steps{{-1, 0},
                                   {1,  0},
                                   {0,  -1},
                                   {0,  1}};
        int result = 0;
        while (!heap.empty()) {
            pair<int, int> item = heap.top();
            heap.pop();
            for (auto &step : steps) {
                int row = item.second >> 8 + step[0];
                int col = item.second & 0xff + step[1];
                if (row >= 0 && col >= 0 && row < m && col < n && heightMap[row][col] >= 0) {
                    result += max(0, item.first - heightMap[row][col]);
                    heap.push(pair<int, int>(max(item.first, heightMap[row][col]), (row << 8) | col));
                    heightMap[row][col] *= -1;
                    heightMap[row][col] -= 1;
                }
            }
        }
        return result;
    }
};