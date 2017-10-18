class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        int moves[4][2] = {{-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1}
        };
        for (int k = 1; k <= N; k++) {
            for (int a = 0; a < m; a++) {
                for (int b = 0; b < n; b++) {
                    for (auto &move : moves) {
                        int row = a + move[0];
                        int col = b + move[1];
                        if (row == -1 || col == -1 || row == m || col == n) {
                            dp[k][a][b]++;
                        } else {
                            dp[k][a][b] += dp[k - 1][row][col];
                            dp[k][a][b] %= 1000000007;
                        }
                    }
                }
            }
        }
        return dp[N][i][j];
    }
};