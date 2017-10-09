class Solution:
    def findPaths(self, m, n, N, i, j):
        """
        :type m: int
        :type n: int
        :type N: int
        :type i: int
        :type j: int
        :rtype: int
        """
        dp = [[[0] * (n) for _ in range(m)] for _ in range(N + 1)]
        moves = ((-1, 0), (1, 0), (0, -1), (0, 1))
        for k in range(1, N + 1):
            for a in range(m):
                for b in range(n):
                    for move in moves:
                        row = a + move[0]
                        col = b + move[1]
                        if row == -1 or col == -1 or row == m or col == n:
                            dp[k][a][b] += 1
                        else:
                            dp[k][a][b] += dp[k - 1][row][col]
                            dp[k][a][b] %= 1000000007
        return dp[N][i][j]
