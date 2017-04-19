class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        dp = [[None] * (len(s) + 1) for i in range(len(t) + 1)]
        dp[0] = [1] * (len(s) + 1)
        for i in range(1, len(t) + 1):
            dp[i][0] = 0
        for i in range(1, len(t) + 1):
            for j in range(1, len(s) + 1):
                dp[i][j] = dp[i][j - 1]
                if t[i - 1] == s[j - 1]:
                    dp[i][j] += dp[i - 1][j - 1]
        return dp[len(t)][len(s)]
