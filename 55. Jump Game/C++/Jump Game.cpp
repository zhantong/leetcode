class Solution {
public:
    bool canJump(vector<int> &nums) {
        int current = 0;
        int i = 0;
        while (i < nums.size() && i <= current) {
            current = max(current, i + nums[i]);
            i++;
        }
        return i == nums.size();
    }
};