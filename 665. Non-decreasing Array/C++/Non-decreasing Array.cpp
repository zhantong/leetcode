class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        bool isModified = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (isModified) {
                    return false;
                }
                isModified = true;
                if (i < 2 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};