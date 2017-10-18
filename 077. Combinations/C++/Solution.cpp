class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        class Utils {
        public:
            void comb(vector<vector<int>> &result, vector<int> &current, int start, int n, int k) {
                if (k == 0) {
                    result.push_back(current);
                } else {
                    for (int i = start; i <= n; i++) {
                        current.push_back(i);
                        comb(result, current, i + 1, n, k - 1);
                        current.pop_back();
                    }
                }
            }
        };
        vector<vector<int>> result;
        Utils utils;
        vector<int> temp;
        utils.comb(result, temp, 1, n, k);
        return result;
    }
};