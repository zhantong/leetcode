class Solution {
public:
    bool isMatch(string s, string p) {
        int lengthS = s.length();
        int lengthP = p.length();
        vector<vector<bool>> dp(lengthS + 1, vector<bool>(lengthP + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= lengthP; j++) {
            dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
        }
        for (int i = 1; i <= lengthS; i++) {
            for (int j = 1; j <= lengthP; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?');
                }
            }
        }
        return dp[lengthS][lengthP];
    }
};