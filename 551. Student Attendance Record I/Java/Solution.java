public class Solution {
    public boolean checkRecord(String s) {
        boolean containsA = false;
        for (int i = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            if ((letter == 'A' && containsA) || (letter == 'L' && i >= 2 && s.charAt(i - 1) == 'L' && s.charAt(i - 2) == 'L')) {
                return false;
            }
            if (letter == 'A' && !containsA) {
                containsA = true;
            }
        }
        return true;
    }
}