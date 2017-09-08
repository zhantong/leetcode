class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int theMin = INT_MAX;
        int theMax = INT_MIN;
        bool isUnsorted = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                theMax = max(theMax, nums[i]);
                theMin = min(theMin, nums[i + 1]);
                isUnsorted = true;
            }
        }
        if (!isUnsorted) {
            return 0;
        }
        int start = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > theMin) {
                start = i;
                break;
            }
        }
        int end = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < theMax) {
                end = i;
                break;
            }
        }
        return end - start + 1;
    }
};