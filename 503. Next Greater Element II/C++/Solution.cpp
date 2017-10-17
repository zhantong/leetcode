class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> sta;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sta.push(i);
        }
        vector<int> result(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            while ((!sta.empty()) && nums[sta.top()] <= nums[i]) {
                sta.pop();
            }
            if (!sta.empty()) {
                result[i] = nums[sta.top()];
            } else {
                result[i] = -1;
            }
            sta.push(i);
        }
        return result;
    }
};