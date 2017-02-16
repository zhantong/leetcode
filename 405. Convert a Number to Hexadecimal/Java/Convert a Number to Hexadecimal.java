public class Solution {
    public String toHex(int num) {
        if (num == 0) {
            return "0";
        }
        String symbols = "0123456789abcdef";
        StringBuilder result = new StringBuilder();
        while (num != 0) {
            int value = num & 0xf;
            result.append(symbols.charAt(value));
            num >>>= 4;
        }
        return result.reverse().toString();
    }
}