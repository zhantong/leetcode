public class Solution {
    public String addStrings(String num1, String num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        StringBuilder builder = new StringBuilder();
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int plus = 0;
            if (i >= 0) {
                plus += num1.charAt(i) - '0';
            }
            if (j >= 0) {
                plus += num2.charAt(j) - '0';
            }
            plus += carry;
            builder.append((char)(plus % 10 + '0'));
            carry = plus / 10;
            i--;
            j--;
        }
        if (carry == 1) {
            builder.append('1');
        }
        return builder.reverse().toString();
    }
}