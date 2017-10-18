class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);
                if (dp[i][j] && j - i + 1 > result.length()) {
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }
};