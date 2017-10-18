class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        class Utils {
        public:
            void subsets(vector<int> &nums, vector<vector<int>> &result, vector<int> &current, int start) {
                result.push_back(current);
                for (int i = start; i < nums.size(); i++) {
                    if (i == start || nums[i] != nums[i - 1]) {
                        current.push_back(nums[i]);
                        subsets(nums, result, current, i + 1);
                        current.pop_back();
                    }
                }
            }
        };
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        Utils utils;
        vector<int> temp;
        utils.subsets(nums, result, temp, 0);
        return result;
    }
};