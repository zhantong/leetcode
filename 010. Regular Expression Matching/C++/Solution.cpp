class Solution {
public:
    bool isMatch(string s, string p) {
        int lengthS = s.length();
        int lengthP = p.length();
        vector<vector<bool>> dp(lengthS + 1, vector<bool>(lengthP + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= lengthS; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= lengthP; j++) {
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        }
        for (int i = 1; i <= lengthS; i++) {
            for (int j = 1; j <= lengthP; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || ((p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[lengthS][lengthP];
    }
};