class Solution {
public:
    string optimalDivision(vector<int> &nums) {
        int length = nums.size();
        string result = "";
        if (length > 0) {
            result += to_string(nums[0]);
        }
        if (length > 1) {
            result += '/';
        }
        if (length > 2) {
            result += '(';
        }
        for (int i = 1; i < length - 1; i++) {
            result += to_string(nums[i]);
            result += '/';
        }
        if (length > 1) {
            result += to_string(nums[length - 1]);
        }
        if (length > 2) {
            result += ')';
        }
        return result;
    }
};