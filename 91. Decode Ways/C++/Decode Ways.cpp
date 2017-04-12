class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
            if (i > 1) {
                string temp = s.substr(i - 2, 2);
                if (temp > "09" && temp < "27") {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[s.length()];
    }
};