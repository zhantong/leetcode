public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] counts = new int[26];
        for (char item : s.toCharArray()) {
            counts[item - 'a']++;
        }
        for (char item : t.toCharArray()) {
            counts[item - 'a']--;
        }
        for (int count : counts) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
}