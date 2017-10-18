class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (auto num : nums) {
            if (nums[abs(num) - 1] < 0) {
                result.push_back(abs(num));
            } else {
                nums[abs(num) - 1] *= -1;
            }
        }
        return result;
    }
};