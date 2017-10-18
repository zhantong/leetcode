class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        class Utils {
        public:
            void combination(vector<vector<int>> &result, vector<int> current, int start, int k, int n) {
                if (k == 0 && n == 0) {
                    result.push_back(current);
                } else if (k > 0 && n > 0) {
                    for (int i = start; i < 10; i++) {
                        current.push_back(i);
                        combination(result, current, i + 1, k - 1, n - i);
                        current.pop_back();
                    }
                }
            }
        };
        vector<vector<int>> result;
        Utils utils;
        utils.combination(result, vector<int>(), 1, k, n);
        return result;
    }
};