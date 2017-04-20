public class Solution {
    public int numDecodings(String s) {
        if (s.isEmpty()) {
            return 0;
        }
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (s.charAt(i - 1) != '0') {
                dp[i] = dp[i - 1];
            }
            if (i > 1) {
                String temp = s.substring(i - 2, i);
                if (temp.compareTo("09") > 0 && temp.compareTo("27") < 0) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[s.length()];
    }
}