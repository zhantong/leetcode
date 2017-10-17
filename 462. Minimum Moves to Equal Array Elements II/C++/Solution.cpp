class Solution {
public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            result += nums[j] - nums[i];
            i++;
            j--;
        }
        return result;
    }
};