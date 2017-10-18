class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        class Utils {
        public:
            bool win(int maxChoosableInteger, int choosed, unordered_map<int, bool> &memory, int total) {
                if (memory.count(choosed) != 0) {
                    return memory[choosed];
                }
                for (int i = 1; i <= maxChoosableInteger; i++) {
                    if ((choosed & (1 << i)) == 0) {
                        if (total <= i || !win(maxChoosableInteger, choosed | (1 << i), memory, total - i)) {
                            memory[choosed] = true;
                            return true;
                        }
                    }
                }
                memory[choosed] = false;
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
        unordered_map<int, bool> memory;
        return utils.win(maxChoosableInteger, 0, memory, desiredTotal);
    }
};