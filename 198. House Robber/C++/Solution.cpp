class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int results[nums.size() + 1] = {0};
        results[0] = 0;
        results[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            results[i] = max(nums[i - 1] + results[i - 2], results[i - 1]);
        }
        return results[nums.size()];
    }
};