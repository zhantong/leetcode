class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        class Utils {
        public:
            int steps[8][2] = {{1,  2},
                {1,  -2},
                {-1, 2},
                {-1, -2},
                {2,  -1},
                {2,  1},
                {-2, -1},
                {-2, 1}
            };

            double dfs(int N, int k, int r, int c, vector<vector<vector<double>>> &dp) {
                if (r < 0 || r >= N || c < 0 || c >= N) {
                    return 0;
                }
                if (k == 0) {
                    return 1;
                }
                if (dp[k][r][c] != 0) {
                    return dp[k][r][c];
                }
                for (auto &step : steps) {
                    dp[k][r][c] += dfs(N, k - 1, r + step[0], c + step[1], dp);
                }
                return dp[k][r][c];
            }
        };
        Utils utils;
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N)));
        return utils.dfs(N, K, r, c, dp) / pow(8, K);
    }
};