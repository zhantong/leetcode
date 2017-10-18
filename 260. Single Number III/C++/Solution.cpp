class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int mixedXor = 0;
        for (auto num : nums) {
            mixedXor ^= num;
        }
        int diff = mixedXor & (mixedXor - 1) ^mixedXor;
        int first = 0;
        int second = 0;
        for (auto num : nums) {
            if (diff & num) {
                first ^= num;
            } else {
                second ^= num;
            }
        }
        return vector<int> {first, second};
    }
};