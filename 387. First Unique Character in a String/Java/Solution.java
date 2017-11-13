public class Solution {
    public int firstUniqChar(String s) {
        int[] counts = new int[26];
        for (char item : s.toCharArray()) {
            counts[item - 'a']++;
        }
        int index = 0;
        for (char item : s.toCharArray()) {
            if (counts[item - 'a'] == 1) {
                return index;
            }
            index++;
        }
        return -1;
    }
}