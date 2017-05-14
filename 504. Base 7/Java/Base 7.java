public class Solution {
    public String convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        int sign = num >= 0 ? 1 : -1;
        num = Math.abs(num);
        StringBuilder builder = new StringBuilder();
        while (num != 0) {
            builder.append(num % 7);
            num /= 7;
        }
        if (sign < 0) {
            builder.append('-');
        }
        return builder.reverse().toString();
    }
}