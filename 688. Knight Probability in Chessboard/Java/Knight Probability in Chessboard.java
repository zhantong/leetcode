class Solution {
    public double knightProbability(int N, int K, int r, int c) {
        class Utils {
            int[][] steps = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

            double dfs(int N, int k, int r, int c, double[][][] dp) {
                if (r < 0 || r >= N || c < 0 || c >= N) {
                    return 0;
                }
                if (k == 0) {
                    return 1;
                }
                if (dp[k][r][c] != 0) {
                    return dp[k][r][c];
                }
                for (int[] step : steps) {
                    dp[k][r][c] += dfs(N, k - 1, r + step[0], c + step[1], dp);
                }
                return dp[k][r][c];
            }
        }
        Utils utils = new Utils();
        return utils.dfs(N, K, r, c, new double[K + 1][N][N]) / Math.pow(8, K);
    }
}