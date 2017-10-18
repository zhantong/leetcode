class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = INT_MIN;
        for (int colStart = 0; colStart < n; colStart++) {
            vector<int> current(m, 0);
            for (int colEnd = colStart; colEnd < n; colEnd++) {
                for (int i = 0; i < m; i++) {
                    current[i] += matrix[i][colEnd];
                }
                set<int> sums;
                sums.insert(0);
                int currentSum = 0;
                for (auto item : current) {
                    currentSum += item;
                    int target = currentSum - k;
                    set<int>::iterator get = sums.lower_bound(target);
                    if (get != sums.end()) {
                        result = max(result, currentSum - *get);
                    }
                    sums.insert(currentSum);
                }
            }
        }
        return result;
    }
};