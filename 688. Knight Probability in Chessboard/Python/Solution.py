class Solution:
    def knightProbability(self, N, K, r, c):
        """
        :type N: int
        :type K: int
        :type r: int
        :type c: int
        :rtype: float
        """

        def dfs(N, k, r, c, dp):
            if r < 0 or r >= N or c < 0 or c >= N:
                return 0
            if k == 0:
                return 1
            if dp[k][r][c] != 0:
                return dp[k][r][c]
            for i, j in ((1, 2), (1, -2), (-1, 2), (-1, -2), (2, -1), (2, 1), (-2, -1), (-2, 1)):
                dp[k][r][c] += dfs(N, k - 1, r + i, c + j, dp)
            return dp[k][r][c]

        return dfs(N, K, r, c, [[[0] * N for _ in range(N)] for _ in range(K + 1)]) / 8 ** K
