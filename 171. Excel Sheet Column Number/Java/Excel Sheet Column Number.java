public class Solution {
    public int titleToNumber(String s) {
        int result = 0;
        for (char letter : s.toCharArray()) {
            result = result * 26 + letter - 'A' + 1;
        }
        return result;
    }
}