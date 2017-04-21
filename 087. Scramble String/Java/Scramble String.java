public class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.equals(s2)) {
            return true;
        }
        if (s1.length() != s2.length()) {
            return false;
        }
        int length = s1.length();
        int[] count = new int[26];
        for (int i = 0; i < length; i++) {
            count[s1.charAt(i) - 'a']++;
            count[s2.charAt(i) - 'a']--;
        }
        for (int item : count) {
            if (item != 0) {
                return false;
            }
        }
        for (int i = 1; i < length; i++) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i))) {
                return true;
            }
            if (isScramble(s1.substring(0, i), s2.substring(length - i)) && isScramble(s1.substring(i), s2.substring(0, length - i))) {
                return true;
            }
        }
        return false;
    }
}