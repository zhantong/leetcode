public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] has = new int[26];
        for (char item : magazine.toCharArray()) {
            has[item - 'a']++;
        }
        for (char item : ransomNote.toCharArray()) {
            if (has[item - 'a'] == 0) {
                return false;
            }
            has[item - 'a']--;
        }
        return true;
    }
}