class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int firstZeroIndex = 0;
        while (firstZeroIndex < nums.size() && nums[firstZeroIndex] != 0) {
            firstZeroIndex++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0 && i > firstZeroIndex) {
                nums[firstZeroIndex] = nums[i];
                nums[i] = 0;
                firstZeroIndex++;
            }
        }
    }
};