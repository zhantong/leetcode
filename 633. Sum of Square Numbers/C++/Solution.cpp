class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = (int) sqrt(c);
        while (left <= right) {
            int current = left * left + right * right;
            if (current == c) {
                return true;
            }
            if (current < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};