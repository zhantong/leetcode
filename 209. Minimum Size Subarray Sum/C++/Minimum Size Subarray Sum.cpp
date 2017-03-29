class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int i = 0;
        int theSum = 0;
        int theMin = INT_MAX;
        for (int j = 0; j < nums.size(); j++) {
            theSum += nums[j];
            while (theSum >= s) {
                theMin = min(theMin, j - i + 1);
                if (theMin == 1) {
                    return theMin;
                }
                theSum -= nums[i];
                i++;
            }
        }
        return theMin == INT_MAX ? 0 : theMin;
    }
};