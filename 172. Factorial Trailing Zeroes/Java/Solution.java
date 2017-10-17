public class Solution {
    public int trailingZeroes(int n) {
        int result = 0;
        long i = 5;
        while (i <= n) {
            result += n / i;
            i *= 5;
        }
        return result;
    }
}