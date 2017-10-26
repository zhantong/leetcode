class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        def reverse(s, i, j):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1

        i = 0
        j = 0
        s = list(s)
        print(s)
        while j < len(s) and s[j] == ' ':
            j += 1
        while j < len(s):
            if s[j] != ' ' or (s[j] == ' ' and j < len(s) - 1 and s[j + 1] != ' '):
                s[i] = s[j]
                i += 1
            j += 1
        s = s[:i]
        s.reverse()
        i = 0
        for j in range(len(s)):
            if j + 1 == len(s) or s[j + 1] == ' ':
                reverse(s, i, j)
                i = j + 2
        return ''.join(s)
