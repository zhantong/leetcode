class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        str = list(s)
        i = 0
        while i < length and str[i] == ' ':
            i += 1
        j = i
        while j < length:
            while j < length and str[j] != ' ':
                j += 1
            str[i:j] = s[i:j][::-1]
            while j < length and str[j] == ' ':
                j += 1
            i = j
        return ''.join(str)
