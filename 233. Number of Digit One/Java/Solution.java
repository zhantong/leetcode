public class Solution {
    public int countDigitOne(int n) {
        int result = 0;
        long times = 1;
        while (times <= n) {
            int a = (int)(n / times);
            int b = (int)(n % times);
            if (a % 10 == 0) {
                result += a / 10 * times;
            } else if (a % 10 == 1) {
                result += a / 10 * times + b + 1;
            } else {
                result += (a / 10 + 1) * times;
            }
            times *= 10;
        }
        return result;
    }
}