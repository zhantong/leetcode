class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if not s:
            return True
        index_s = 0
        for item in t:
            if item == s[index_s]:
                if index_s == len(s) - 1:
                    return True
                index_s += 1
        return False
