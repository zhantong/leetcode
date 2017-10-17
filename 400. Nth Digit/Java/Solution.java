public class Solution {
    public int findNthDigit(int n) {
        int digits = 1;
        int start = 1;
        long length = 9;
        while (n > digits * length) {
            n -= digits * length;
            digits++;
            start *= 10;
            length *= 10;
        }
        n--;
        int number = start + n / digits;
        return Character.getNumericValue(String.valueOf(number).charAt(n % digits));
    }
}