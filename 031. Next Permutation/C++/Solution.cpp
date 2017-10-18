class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        sort(nums.begin() + i + 1, nums.end());
    }
};