class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            int current = matrix[i][j];
            if (current == target) {
                return true;
            } else if (current > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};