class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        cuts = [0] * length
        palindrome = [[False] * length for i in range(length)]
        for i in range(length):
            current = i
            for j in range(i + 1):
                if s[i] == s[j] and (i - j < 2 or palindrome[j + 1][i - 1]):
                    palindrome[j][i] = True
                    current = 0 if j == 0 else min(current, cuts[j - 1] + 1)
            cuts[i] = current
        return cuts[length - 1]
