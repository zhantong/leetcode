class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int result = 0;
        vector<int> soFar(nums.size() + 1);
        unordered_map<int, int> memory;
        memory[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            soFar[i] = soFar[i - 1] + (nums[i - 1] == 1 ? 1 : -1);
            if (memory.find(soFar[i]) == memory.end()) {
                memory[soFar[i]] = i;
            } else {
                result = max(result, i - memory[soFar[i]]);
            }
        }
        return result;
    }
};