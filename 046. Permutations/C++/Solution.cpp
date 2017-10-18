class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> newResult;
            for (int j = 0; j <= i; j++) {
                for (auto item : result) {
                    vector<int> newItem(item);
                    newItem.insert(newItem.begin() + j, nums[i]);
                    newResult.push_back(newItem);
                }
            }
            result = newResult;
        }
        return result;
    }
};