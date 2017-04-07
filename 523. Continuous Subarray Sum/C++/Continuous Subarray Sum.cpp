class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> memory;
        memory[0] = -1;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            if (k != 0) {
                currentSum %= k;
            }
            if (memory.find(currentSum) != memory.end()) {
                if (i - memory[currentSum] > 1) {
                    return true;
                }
            } else {
                memory[currentSum] = i;
            }
        }
        return false;
    }
};