class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool isPrevZero = (n & 1) == 0;
        long current = 2;
        while (current <= n) {
            if (isPrevZero == ((n & current) == 0)) {
                return false;
            }
            isPrevZero = !isPrevZero;
            current <<= 1;
        }
        return true;
    }
};