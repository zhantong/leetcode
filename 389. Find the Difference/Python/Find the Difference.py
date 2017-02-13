class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        result_ord = 0
        for item in s:
            result_ord ^= ord(item)
        for item in t:
            result_ord ^= ord(item)
        return chr(result_ord)
