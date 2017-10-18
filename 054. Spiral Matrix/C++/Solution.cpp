class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n;
        int up = 0;
        int down = m;
        while (left < right && up < down) {
            for (int j = left; j < right; j++) {
                result.push_back(matrix[up][j]);
            }
            up++;
            if (up == down) {
                break;
            }
            for (int i = up; i < down; i++) {
                result.push_back(matrix[i][right - 1]);
            }
            right--;
            if (right == left) {
                break;
            }
            for (int j = right - 1; j >= left; j--) {
                result.push_back(matrix[down - 1][j]);
            }
            down--;
            if (down == up) {
                break;
            }
            for (int i = down - 1; i >= up; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
            if (left == right) {
                break;
            }
        }
        return result;
    }
};