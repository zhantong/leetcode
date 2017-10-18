class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int duplicate = 0;
        int miss = 0;
        for (int num : nums) {
            if (nums[abs(num) - 1] < 0) {
                duplicate = abs(num);
            } else {
                nums[abs(num) - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                miss = i + 1;
            }
        }
        return vector<int> {duplicate, miss};
    }
};