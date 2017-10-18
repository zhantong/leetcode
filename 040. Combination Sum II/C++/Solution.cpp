class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        class Utils {
        public:
            void combination(vector<int> &candidates, int target, int start, vector<vector<int>> &result,
                             vector<int> &current) {
                if (target < 0) {
                    return;
                }
                if (target == 0) {
                    result.push_back(current);
                }
                for (int i = start; i < candidates.size(); i++) {
                    if (i > start && candidates[i] == candidates[i - 1]) {
                        continue;
                    }
                    current.push_back(candidates[i]);
                    combination(candidates, target - candidates[i], i + 1, result, current);
                    current.pop_back();
                }
            }
        };
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        Utils utils;
        vector<int> temp;
        utils.combination(candidates, target, 0, result, temp);
        return result;
    }
};