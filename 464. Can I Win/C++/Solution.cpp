class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        class Utils {
        public:
            int toKey(vector<bool> &choosed) {
                int result = 0;
                for (auto item : choosed) {
                    result <<= 1;
                    if (item) {
                        result |= 1;
                    }
                }
                return result;
            }

            bool win(vector<bool> &choosed, unordered_map<int, bool> &memory, int total) {
                int key = toKey(choosed);
                if (memory.find(key) != memory.end()) {
                    return memory[key];
                }
                for (int i = 1; i < choosed.size(); i++) {
                    if (!choosed[i]) {
                        choosed[i] = true;
                        if (total <= i || !win(choosed, memory, total - i)) {
                            memory[key] = true;
                            choosed[i] = false;
                            return true;
                        }
                        choosed[i] = false;
                    }
                }
                memory[key] = false;
                return false;
            }
        };
        if (desiredTotal == 0) {
            return true;
        }
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        Utils utils;
        vector<bool> choosed(maxChoosableInteger + 1, false);
        unordered_map<int, bool> memory;
        return utils.win(choosed, memory, desiredTotal);
    }
};