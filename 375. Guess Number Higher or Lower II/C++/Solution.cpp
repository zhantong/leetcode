class Solution {
public:
    int getMoneyAmount(int n) {
        class Utils {
        public:
            int getMoney(int start, int end, vector<vector<int>> &memory) {
                if (start >= end) {
                    return 0;
                }
                if (memory[start][end] != 0) {
                    return memory[start][end];
                }
                int result = INT_MAX;
                for (int i = start; i <= end; i++) {
                    int current = i + max(getMoney(start, i - 1, memory), getMoney(i + 1, end, memory));
                    result = min(result, current);
                }
                memory[start][end] = result;
                return result;
            }
        };
        vector<vector<int>> memory(n + 1, vector<int>(n + 1, 0));
        Utils utils;
        return utils.getMoney(1, n, memory);
    }
};