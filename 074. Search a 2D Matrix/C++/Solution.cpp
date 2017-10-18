class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int value = matrix[mid / n][mid % n];
            if (value == target) {
                return true;
            } else if (value > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};