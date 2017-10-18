class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int xorValue = x ^ y;
        while (xorValue != 0) {
            xorValue &= (xorValue - 1);
            count++;
        }
        return count;
    }
};