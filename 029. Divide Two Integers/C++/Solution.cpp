class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend > 0) == (divisor > 0);
        long longDivisor = abs((long) divisor);
        long a = abs((long) dividend);
        long b = longDivisor;
        long result = 0;
        int current = 1;
        while (a >= longDivisor) {
            a -= b;
            result += current;
            current += current;
            b += b;
            if (a < b) {
                b = longDivisor;
                current = 1;
            }
        }
        if (sign) {
            return (int) min(result, (long)INT_MAX);
        }
        return (int) max(-result, (long)INT_MIN);
    }
};