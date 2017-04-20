class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int theMin = nums[0];
        int theMax = nums[0];
        for (auto num : nums) {
            theMin = min(theMin, num);
            theMax = max(theMax, num);
        }
        int gap = (int) ceil(((double) theMax - theMin) / (nums.size() - 1));
        vector<int> bucketMin(nums.size() - 1, theMax + 1);
        vector<int> bucketMax(nums.size() - 1, theMin - 1);
        for (auto num : nums) {
            if (num == theMax || num == theMin) {
                continue;
            }
            int index = (num - theMin) / gap;
            bucketMin[index] = min(bucketMin[index], num);
            bucketMax[index] = max(bucketMax[index], num);
        }
        int prev = theMin;
        for (int i = 0; i < bucketMax.size(); i++) {
            if (bucketMin[i] == theMax + 1) {
                continue;
            }
            gap = max(gap, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        gap = max(gap, theMax - prev);
        return gap;
    }
};