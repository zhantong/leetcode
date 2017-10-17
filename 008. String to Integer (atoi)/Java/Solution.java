public class Solution {
    public int myAtoi(String str) {
        int length = str.length();
        int index = 0;
        int sign = 1;
        int result = 0;
        while (index < length && str.charAt(index) == ' ') {
            index++;
        }
        if (index < length && str.charAt(index) == '-') {
            sign = -1;
            index++;
        } else if (index < length && str.charAt(index) == '+') {
            index++;
        }
        while (index < length && str.charAt(index) >= '0' && str.charAt(index) <= '9') {
            if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && str.charAt(index) - '0' > 7)) {
                if (sign > 0) {
                    return Integer.MAX_VALUE;
                } else {
                    return Integer.MIN_VALUE;
                }
            }
            result = result * 10 + str.charAt(index) - '0';
            index++;
        }
        return sign * result;
    }
}