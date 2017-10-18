public class Solution {
    public String intToRoman(int num) {
        String[] words = new String[] {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int[] values = new int[] {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            while (num >= values[i]) {
                builder.append(words[i]);
                num -= values[i];
            }
        }
        return builder.toString();
    }
}