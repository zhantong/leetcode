class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.size() == 0) {
            return vector<string>();
        }
        int start = 0;
        long offset = nums[0];
        vector<string> result;
        for (int i = 1; i < nums.size(); i++) {
            if (i + offset != nums[i]) {
                if (start == i - 1) {
                    result.push_back(to_string(nums[start]));
                } else {
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                }
                offset = nums[i] - i;
                start = i;
            }
        }
        if (start == nums.size() - 1) {
            result.push_back(to_string(nums[start]));
        } else {
            result.push_back(to_string(nums[start]) + "->" + to_string(nums.back()));
        }
        return result;
    }
};