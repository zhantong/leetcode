class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto &str : strs) {
            int zeros = 0;
            int ones = 0;
            for (auto &letter : str) {
                if (letter == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            for (int i = m; i >= 0; i--) {
                for (int j = n; j >= 0; j--) {
                    if (i >= zeros && j >= ones) {
                        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};