public class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int[] result = new int[num1.length() + num2.length()];
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int pos1 = i + j;
                int pos2 = i + j + 1;
                mul += result[pos2];
                result[pos1] += mul / 10;
                result[pos2] = mul % 10;
            }
        }
        StringBuilder builder = new StringBuilder();
        if (result[0] != 0) {
            builder.append(result[0]);
        }
        for (int i = 1; i < result.length; i++) {
            builder.append(result[i]);
        }
        return builder.toString();
    }
}