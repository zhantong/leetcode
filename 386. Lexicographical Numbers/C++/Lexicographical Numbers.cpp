class Solution {
public:
    vector<int> lexicalOrder(int n) {
        class Utils {
        public:
            void dfs(vector<int> &result, int current, int n) {
                if (current > n) {
                    return;
                }
                result.push_back(current);
                current *= 10;
                for (int i = 0; i < 10; i++) {
                    if (current + i <= n) {
                        dfs(result, current + i, n);
                    }
                }
            }
        };
        vector<int> result;
        Utils utils;
        for (int i = 1; i < 10; i++) {
            utils.dfs(result, i, n);
        }
        return result;
    }
};