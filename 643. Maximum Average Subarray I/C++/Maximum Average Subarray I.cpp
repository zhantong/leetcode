class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int i = 0;
        long sum = 0;
        long maxSum = LONG_MIN;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (j - i == k - 1) {
                maxSum = max(maxSum, sum);
                sum -= nums[i];
                i++;
            }
        }
        return (double) maxSum / k;
    }
};