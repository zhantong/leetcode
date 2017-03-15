class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i - 1]) {
            i++;
        }
        if (i == nums.size()) {
            return 1;
        }
        bool isIncrease = nums[0] > nums[i];
        int result = 2;
        for (int j = i + 1; j < nums.size(); j++) {
            if ((isIncrease && nums[j] > nums[j - 1]) || (!isIncrease && nums[j] < nums[j - 1])) {
                result++;
                isIncrease = !isIncrease;
            }
        }
        return result;
    }
};