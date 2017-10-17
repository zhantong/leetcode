class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        length = len(s)
        for i in range(0, length, 2 * k):
            if i + k >= length:
                s = s[:i] + s[i:][::-1]
            else:
                s = s[:i] + s[i:i + k][::-1] + s[i + k:]
        return s
