class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        class Utils {
        public:
            int dfs(vector<vector<int>> &matrix, int i, int j, int m, int n, int prev, vector<vector<int>> &memory) {
                if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] >= prev) {
                    return 0;
                }
                if (memory[i][j] != 0) {
                    return memory[i][j];
                }
                int result = 0;
                int current = matrix[i][j];
                result = max(result, dfs(matrix, i - 1, j, m, n, current, memory));
                result = max(result, dfs(matrix, i + 1, j, m, n, current, memory));
                result = max(result, dfs(matrix, i, j - 1, m, n, current, memory));
                result = max(result, dfs(matrix, i, j + 1, m, n, current, memory));
                result++;
                memory[i][j] = result;
                return result;
            }
        };
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memory(m, vector<int>(n, 0));
        int result = 0;
        Utils utils;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, utils.dfs(matrix, i, j, m, n, INT_MAX, memory));
            }
        }
        return result;
    }
};