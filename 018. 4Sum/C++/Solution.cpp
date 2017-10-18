class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                for (int j = i + 1; j < nums.size() - 2; j++) {
                    if (j == i + 1 || nums[j] > nums[j - 1]) {
                        int low = j + 1;
                        int high = nums.size() - 1;
                        int goal = target - nums[i] - nums[j];
                        while (low < high) {
                            if (nums[low] + nums[high] == goal) {
                                result.push_back({nums[i], nums[j], nums[low], nums[high]});
                                while (low < high && nums[low] == nums[low + 1]) {
                                    low++;
                                }
                                low++;
                                while (low < high && nums[high] == nums[high - 1]) {
                                    high--;
                                }
                                high--;
                            } else if (nums[low] + nums[high] > goal) {
                                high--;
                            } else {
                                low++;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};