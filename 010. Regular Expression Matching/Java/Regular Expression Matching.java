public class Solution {
    public boolean isMatch(String s, String p) {
        int lengthS = s.length();
        int lengthP = p.length();
        boolean[][] dp = new boolean[lengthS + 1][lengthP + 1];
        dp[0][0] = true;
        for (int i = 1; i <= lengthS; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= lengthP; j++) {
            dp[0][j] = j > 1 && p.charAt(j - 1) == '*' && dp[0][j - 2];
        }
        for (int i = 1; i <= lengthS; i++) {
            for (int j = 1; j <= lengthP; j++) {
                if (p.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 2] || ((p.charAt(j - 2) == s.charAt(i - 1) || p.charAt(j - 2) == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (p.charAt(j - 1) == s.charAt(i - 1) || p.charAt(j - 1) == '.');
                }
            }
        }
        return dp[lengthS][lengthP];
    }
}