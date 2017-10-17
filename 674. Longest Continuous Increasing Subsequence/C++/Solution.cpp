class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int count = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
            } else {
                result = max(result, count);
                count = 1;
            }
        }
        result = max(result, count);
        return result;
    }
};