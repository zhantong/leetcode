class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        class Utils {
        public:
            void subsequence(vector<int> &nums, set <vector<int>> &result, vector<int> &current, int start) {
                if (current.size() >= 2) {
                    result.insert(vector<int>(current));
                }
                for (int i = start; i < nums.size(); i++) {
                    if (current.empty() || current.back() <= nums[i]) {
                        current.push_back(nums[i]);
                        subsequence(nums, result, current, i + 1);
                        current.pop_back();
                    }
                }
            }
        };
        set <vector<int>> result;
        Utils utils;
        vector<int> temp;
        utils.subsequence(nums, result, temp, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};