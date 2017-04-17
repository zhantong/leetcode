class Solution {
public:
    bool canCross(vector<int> &stones) {
        class Utils {
        public:
            bool backTrace(vector<int> &stones, int current, int length, unordered_map<long, bool> memory) {
                long key = current;
                key = (key << 32) | length;
                if (memory.find(key) != memory.end()) {
                    return memory[key];
                }
                if (current == 0 && length == 1) {
                    memory[key] = true;
                    return true;
                }
                if (current == 0) {
                    memory[key] = false;
                    return false;
                }
                for (int i = current - 1; i >= 0; i--) {
                    int tempLength = stones[current] - stones[i];
                    if (tempLength < length - 1) {
                        continue;
                    }
                    if (tempLength > length + 1) {
                        memory[key] = false;
                        return false;
                    }
                    if (backTrace(stones, i, tempLength, memory)) {
                        memory[key] = true;
                        return true;
                    }
                }
                memory[key] = false;
                return false;
            }
        };
        int last = stones.back();
        unordered_map<long, bool> memory;
        Utils utils;
        for (int i = stones.size() - 2; i >= 0; i--) {
            if (utils.backTrace(stones, i, last - stones[i], memory)) {
                return true;
            }
        }
        return false;
    }
};