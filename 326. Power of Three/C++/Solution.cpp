class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && ((int) pow((double) 3, 19)) % n == 0;
    }
};