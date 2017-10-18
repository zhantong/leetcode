class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> results(target + 1);
        results[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (auto &num : nums) {
                if (i - num >= 0) {
                    results[i] += results[i - num];
                }
            }
        }
        return results[target];
    }
};