class Solution {
public:
    int minMoves(vector<int> &nums) {
        int sum = 0;
        int min = INT32_MAX;
        for (int num : nums) {
            sum += num;
            if (num < min) {
                min = num;
            }
        }
        return sum - min * nums.size();
    }
};