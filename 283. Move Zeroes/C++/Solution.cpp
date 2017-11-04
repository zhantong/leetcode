class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        for (auto num : nums) {
            if (num != 0) {
                nums[i] = num;
                i++;
            }
        }
        while (i < nums.size()) {
            nums[i] = 0;
            i++;
        }
    }
};