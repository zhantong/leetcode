class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int index = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] && count < 2) {
                nums[index] = nums[i];
                index += 1;
                count += 1;
            } else if (nums[i] != nums[i - 1]) {
                nums[index] = nums[i];
                index += 1;
                count = 1;
            }
        }
        return index;
    }
};