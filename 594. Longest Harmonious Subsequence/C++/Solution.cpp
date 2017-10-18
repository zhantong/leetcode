class Solution {
public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> memory;
        for (int num : nums) {

            memory[num]++;
        }
        int result = 0;
        for (auto item : memory) {
            if (memory.find(item.first + 1) != memory.end()) {
                result = max(result, item.second + memory[item.first + 1]);
            }
        }
        return result;
    }
};