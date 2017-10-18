class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int theXor = m ^ n;
        int diffIndex = 31;
        while (diffIndex >= 0 && (theXor & 1 << diffIndex) == 0) {
            diffIndex--;
        }
        return m & 0xffffffff << (diffIndex + 1);
    }
};