public class Solution {
    public int divide(int dividend, int divisor) {
        boolean sign = (dividend > 0) == (divisor > 0);
        long longDivisor = Math.abs((long)divisor);
        long a = Math.abs((long)dividend);
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
            return (int) Math.min(result, 2147483647);
        }
        return (int) Math.max(-result, -2147483648);
    }
}