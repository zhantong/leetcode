class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = ""
        dp = [[False] * len(s) for i in range(len(s))]
        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                dp[i][j] = s[i] == s[j] and (j - i < 3 or dp[i + 1][j - 1])
                if dp[i][j] and j - i + 1 > len(result):
                    result = s[i:j + 1]
        return result
