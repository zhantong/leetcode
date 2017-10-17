public class Solution {
    public int maxProduct(String[] words) {
        int[] bits = new int[words.length];
        int result = 0;
        for (int i = 0; i < words.length; i++) {
            int bit = 0;
            for (char letter : words[i].toCharArray()) {
                bit |= 1 << (letter - 'a');
            }
            bits[i] = bit;
        }
        for (int i = 0; i < bits.length; i++) {
            for (int j = i + 1; j < bits.length; j++) {
                if ((bits[i] & bits[j]) == 0 && words[i].length() * words[j].length() > result) {
                    result = words[i].length() * words[j].length();
                }
            }
        }
        return result;
    }
}