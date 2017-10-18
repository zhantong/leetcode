class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0;
        int result = 0;
        unordered_map<int, int> memory;
        memory[0] = 1;
        for (int num : nums) {
            sum += num;
            if (memory.count(sum - k)) {
                result += memory[sum - k];
            }
            if (!memory.count(sum)) {
                memory[sum] = 0;
            }
            memory[sum]++;
        }
        return result;
    }
};