class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        int range[] = {-1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int current = 0;
                int count = 0;
                for (int a : range) {
                    for (int b : range) {
                        int row = i + a;
                        int col = j + b;
                        if (row >= 0 && row < m && col >= 0 && col < n) {
                            current += M[row][col];
                            count++;
                        }
                    }
                }
                result[i][j] = (int) floor((double) current / count);
            }
        }
        return result;
    }
};