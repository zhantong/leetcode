class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int length1 = s1.length() + 1;
        int length2 = s2.length() + 1;
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<bool>> dp(length1, vector<bool>(length2, false));
        dp[0][0] = true;
        for (int i = 1; i < length1; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int j = 1; j < length2; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (int i = 1; i < length1; i++) {
            for (int j = 1; j < length2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[length1 - 1][length2 - 1];
    }
};