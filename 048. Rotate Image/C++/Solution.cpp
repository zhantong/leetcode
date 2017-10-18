class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m / 2; i++) {
            vector<int> temp = matrix[i];
            matrix[i] = matrix[m - i - 1];
            matrix[m - i - 1] = temp;
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};