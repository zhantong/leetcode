class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for (int row = 1; row <= rowIndex; row++) {
            for (int i = row; i > 0; i--) {
                result[i] += result[i - 1];
            }
        }
        return result;
    }
};