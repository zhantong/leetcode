class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        for (auto num : nums) {
            int index = num > 0 ? num : -num;
            index--;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};