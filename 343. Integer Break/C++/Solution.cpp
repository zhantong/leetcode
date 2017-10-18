class Solution {
public:
    int integerBreak(int n) {
        switch (n) {
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 4;
        default:
            int result = 1;
            while (n > 4) {
                n -= 3;
                result *= 3;
            }
            if (n > 1) {
                result *= n;
            }
            return result;
        }
    }
};