class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        queue<pair<int, int>> que;
        int m = matrix.size();
        int n = matrix[0].size();
        int MAX_VALUE = m + n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = MAX_VALUE;
                } else {
                    que.push(pair<int, int>(i, j));
                }
            }
        }
        int current = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int k = 0; k < size; k++) {
                pair<int, int> coord = que.front();
                que.pop();
                int i = coord.first;
                int j = coord.second;
                if (i > 0 && matrix[i - 1][j] == MAX_VALUE) {
                    matrix[i - 1][j] = current;
                    que.push(pair<int, int>(i - 1, j));
                }
                if (i < m - 1 && matrix[i + 1][j] == MAX_VALUE) {
                    matrix[i + 1][j] = current;
                    que.push(pair<int, int>(i + 1, j));
                }
                if (j > 0 && matrix[i][j - 1] == MAX_VALUE) {
                    matrix[i][j - 1] = current;
                    que.push(pair<int, int>(i, j - 1));
                }
                if (j < n - 1 && matrix[i][j + 1] == MAX_VALUE) {
                    matrix[i][j + 1] = current;
                    que.push(pair<int, int>(i, j + 1));
                }
            }
            current++;
        }
        return matrix;
    }
};