class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                int low = i + 1;
                int high = nums.size() - 1;
                int target = -nums[i];
                while (low < high) {
                    if (nums[low] + nums[high] == target) {
                        result.push_back({nums[i], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) {
                            low++;
                        }
                        low++;
                        while (low < high && nums[high] == nums[high - 1]) {
                            high--;
                        }
                        high--;
                    } else if (nums[low] + nums[high] > target) {
                        high--;
                    } else {
                        low++;
                    }
                }
            }
        }
        return result;
    }
};