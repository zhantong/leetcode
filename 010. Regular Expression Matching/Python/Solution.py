class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        length_s = len(s)
        length_p = len(p)
        dp = [[False] * (length_p + 1) for i in range(length_s + 1)]
        dp[0][0] = True
        for i in range(1, length_s + 1):
            dp[i][0] = False
        for j in range(1, length_p + 1):
            dp[0][j] = j > 1 and p[j - 1] == '*' and dp[0][j - 2]
        for i in range(1, length_s + 1):
            for j in range(1, length_p + 1):
                if p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or ((p[j - 2] == s[i - 1]
                                                 or p[j - 2] == '.') and dp[i - 1][j])
                else:
                    dp[i][j] = dp[i - 1][j - 1] and (p[j - 1] == s[i - 1] or p[j - 1] == '.')
        return dp[length_s][length_p]
