public class Solution {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder result = new StringBuilder();
        int countK = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            char letter = S.charAt(i);
            if (letter != '-') {
                result.append(letter);
                countK++;
                if (countK == K) {
                    result.append('-');
                    countK = 0;
                }
            }
        }
        if (result.length() != 0 && result.charAt(result.length() - 1) == '-') {
            result.deleteCharAt(result.length() - 1);
        }
        return result.reverse().toString().toUpperCase();
    }
}