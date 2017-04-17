class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int hope = 1;
        int result = 0;
        int index = 0;
        while (hope <= n) {
            if (index < nums.size() && nums[index] <= hope) {
                hope += nums[index];
                index++;
            } else {
                result++;
                if (n - hope < hope) {
                    break;
                }
                hope += hope;
            }
        }
        return result;
    }
};