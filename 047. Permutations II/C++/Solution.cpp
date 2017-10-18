class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            vector<vector<int>> currentResult;
            for (const auto &item : result) {
                for (int j = 0; j <= i; j++) {
                    if (j > 0 && num == item[j - 1]) {
                        break;
                    }
                    vector<int> temp = item;
                    temp.insert(temp.begin() + j, num);
                    currentResult.push_back(temp);
                }
            }
            result = currentResult;
        }
        return result;
    }
};