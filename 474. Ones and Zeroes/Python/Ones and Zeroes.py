class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n + 1) for i in range(m + 1)]
        for str in strs:
            zeros = 0
            ones = 0
            for letter in str:
                if letter == '0':
                    zeros += 1
                else:
                    ones += 1
            for i in range(m, -1, -1):
                for j in range(n, -1, -1):
                    if i >= zeros and j >= ones:
                        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
        return dp[m][n]
