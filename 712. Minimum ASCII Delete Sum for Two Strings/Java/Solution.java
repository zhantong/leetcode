class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        int length1 = c1.length;
        int length2 = c2.length;
        int[][] dp = new int[length1 + 1][length2 + 1];
        for (int i = 1; i <= length1; i++) {
            dp[i][0] += dp[i - 1][0] + c1[i - 1];
        }
        for (int j = 1; j <= length2; j++) {
            dp[0][j] += dp[0][j - 1] + c2[j - 1];
        }
        for (int i = 1; i <= length1; i++) {
            for (int j = 1; j <= length2; j++) {
                if (c1[i - 1] == c2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i][j - 1] + c2[j - 1], dp[i - 1][j] + c1[i - 1]);
                }
            }
        }
        return dp[length1][length2];
    }
}