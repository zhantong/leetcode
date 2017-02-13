public class Solution {
    public char findTheDifference(String s, String t) {
        char result = 0;
        for (char item : s.toCharArray()) {
            result ^= item;
        }
        for (char item : t.toCharArray()) {
            result ^= item;
        }
        return result;
    }
}