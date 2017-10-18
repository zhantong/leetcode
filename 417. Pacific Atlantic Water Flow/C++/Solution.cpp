class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        class Utils {
        public:
            void dfs(vector<vector<int>> &matrix, vector<vector<bool >> &visited, int i, int j, int m, int n) {
                if (visited[i][j]) {
                    return;
                }
                visited[i][j] = true;
                if (i > 0 && !visited[i - 1][j] && matrix[i][j] <= matrix[i - 1][j]) {
                    dfs(matrix, visited, i - 1, j, m, n);
                }
                if (i < m && !visited[i + 1][j] && matrix[i][j] <= matrix[i + 1][j]) {
                    dfs(matrix, visited, i + 1, j, m, n);
                }
                if (j > 0 && !visited[i][j - 1] && matrix[i][j] <= matrix[i][j - 1]) {
                    dfs(matrix, visited, i, j - 1, m, n);
                }
                if (j < n && !visited[i][j + 1] && matrix[i][j] <= matrix[i][j + 1]) {
                    dfs(matrix, visited, i, j + 1, m, n);
                }
            }
        };
        if (matrix.size() == 0) {
            return vector<pair<int, int>>();
        }
        Utils utils;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool >> pacific(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            utils.dfs(matrix, pacific, i, 0, m - 1, n - 1);
        }
        for (int j = 0; j < n; j++) {
            utils.dfs(matrix, pacific, 0, j, m - 1, n - 1);
        }
        vector<vector<bool >> atlantic(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            utils.dfs(matrix, atlantic, i, n - 1, m - 1, n - 1);
        }
        for (int j = 0; j < n; j++) {
            utils.dfs(matrix, atlantic, m - 1, j, m - 1, n - 1);
        }
        vector<pair<int, int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back(pair<int, int> {i, j});
                }
            }
        }
        return result;
    }
};