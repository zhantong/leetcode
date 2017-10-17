class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int numsLength = nums.size();
        if (numsLength == 0) {
            return 0;
        }
        vector<int> lengths(numsLength, 1);
        vector<int> counts(numsLength, 1);
        int maxLength = INT_MIN;
        for (int i = 0; i < numsLength; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengths[i] == lengths[j] + 1) {
                        counts[i] += counts[j];
                    } else if (lengths[i] < lengths[j] + 1) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    }
                }
            }
            maxLength = max(maxLength, lengths[i]);
        }
        int result = 0;
        for (int i = 0; i < numsLength; i++) {
            if (lengths[i] == maxLength) {
                result += counts[i];
            }
        }
        return result;
    }
};