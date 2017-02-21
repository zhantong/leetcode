class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        pattern = {}
        exist = {}
        for i in range(0, len(s)):
            s_in = s[i] in exist
            t_in = t[i] in pattern
            if s_in and t_in:
                if ord(t[i]) + pattern[t[i]] != ord(s[i]):
                    return False
            elif not s_in and not t_in:
                pattern[t[i]] = ord(s[i]) - ord(t[i])
                exist[s[i]] = True
            else:
                return False
        return True
