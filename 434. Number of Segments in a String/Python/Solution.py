class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for i in range(0, len(s)):
            if s[i] != ' ' and (i == 0 or s[i - 1] == ' '):
                result += 1
        return result
