class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int current = nums[i] + nums[j] + nums[k];
                if (current == target) {
                    return current;
                }
                if (abs(current - target) < abs(result - target)) {
                    result = current;
                }
                if (current > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};