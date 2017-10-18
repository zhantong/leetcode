class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        if (numRows >= 1) {
            result[0] = vector<int> {1};
        }
        if (numRows >= 2) {
            result[1] = vector<int> {1, 1};
        }
        for (int row = 3; row <= numRows; row++) {
            vector<int> current(row);
            current[0] = 1;
            current[row - 1] = 1;
            for (int i = 1; i < row - 1; i++) {
                current[i] = result[row - 2][i - 1] + result[row - 2][i];
            }
            result[row - 1] = current;
        }
        return result;
    }
};