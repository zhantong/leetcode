class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        class Utils {
        public:
            void combination(vector<int> &candidates, vector<vector<int>> &result, vector<int> &current, int start,
                             int left) {
                if (left == 0) {
                    result.push_back(current);
                } else {
                    for (int i = start; i < candidates.size(); i++) {
                        int candidate = candidates[i];
                        if (candidate <= left) {
                            current.push_back(candidate);
                            combination(candidates, result, current, i, left - candidate);
                            current.pop_back();
                        }
                    }
                }
            }
        };
        vector<vector<int>> result;
        Utils utils;
        vector<int> temp;
        utils.combination(candidates, result, temp, 0, target);
        return result;
    }
};