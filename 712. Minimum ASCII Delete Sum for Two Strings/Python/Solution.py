class Solution:
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        length_1 = len(s1)
        length_2 = len(s2)
        dp = [[0] * (length_2 + 1) for _ in range(length_1 + 1)]
        for i in range(1, length_1 + 1):
            dp[i][0] += dp[i - 1][0] + ord(s1[i - 1])
        for j in range(1, length_2 + 1):
            dp[0][j] += dp[0][j - 1] + ord(s2[j - 1])
        for i in range(1, length_1 + 1):
            for j in range(1, length_2 + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i][j - 1] + ord(s2[j - 1]), dp[i - 1][j] + ord(s1[i - 1]))
        return dp[length_1][length_2]
