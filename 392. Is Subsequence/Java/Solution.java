public class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.isEmpty()) {
            return true;
        }
        int indexS = 0;
        for (char item : t.toCharArray()) {
            if (item == s.charAt(indexS)) {
                if (indexS == s.length() - 1) {
                    return true;
                }
                indexS++;
            }
        }
        return false;
    }
}