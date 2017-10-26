class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        class Utils {
        public:
            bool partition(vector<int> &nums, vector<int> &currents, int target, int start) {
                if (start == -1) {
                    return true;
                }
                for (int i = 0; i < currents.size(); i++) {
                    if (currents[i] + nums[start] <= target) {
                        currents[i] += nums[start];
                        if (partition(nums, currents, target, start - 1)) {
                            return true;
                        }
                        currents[i] -= nums[start];
                    }
                }
                return false;
            }
        };
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        sort(nums.begin(), nums.end());
        Utils utils;
        vector<int> temp(k, 0);
        return utils.partition(nums, temp, target, nums.size() - 1);
    }
};