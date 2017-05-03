class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        reverse = s[::-1]
        for i in range(len(s) + 1):
            if s.startswith(reverse[i:]):
                return reverse[:i] + s
