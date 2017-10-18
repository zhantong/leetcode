class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int i = 0;
        int j = 0;
        result.push_back(matrix[0][0]);
        while (i != m || j != n) {
            if ((i + j) % 2) {
                if (i < m && j == 0) {
                    i++;
                } else if (i == m) {
                    j++;
                } else {
                    i++;
                    j--;
                }
            } else {
                if (i == 0 && j < n) {
                    j++;
                } else if (j == n) {
                    i++;
                } else {
                    i--;
                    j++;
                }
            }
            result.push_back(matrix[i][j]);
        }
        return result;
    }
};