class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            if (window.find(nums[i]) != window.end()) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};