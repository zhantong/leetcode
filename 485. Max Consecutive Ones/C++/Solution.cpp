class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int result = 0;
        int count = 0;
        for (auto num : nums) {
            if (num == 0) {
                result = max(result, count);
                count = 0;
            } else {
                count++;
            }
        }
        result = max(result, count);
        return result;
    }
};