class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && 0x80000000 % n == 0;
    }
};