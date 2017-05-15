public class Solution {
    public boolean detectCapitalUse(String word) {
        boolean sawLower = false;
        boolean sawOneUpper = false;
        boolean sawTwoUpper = false;
        for (char letter : word.toCharArray()) {
            if (letter >= 'A' && letter <= 'Z') {
                if (sawLower) {
                    return false;
                }
                if (sawOneUpper) {
                    sawTwoUpper = true;
                } else {
                    sawOneUpper = true;
                }
            }
            if (letter >= 'a' && letter <= 'z') {
                if (sawTwoUpper) {
                    return false;
                }
                sawLower = true;
            }
        }
        return true;
    }
}