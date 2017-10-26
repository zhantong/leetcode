class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        contains_A = False
        for i, letter in enumerate(s):
            if (letter == 'A' and contains_A) or (letter == 'L' and i >= 2 and s[i - 1] == 'L' and s[i - 2] == 'L'):
                return False
            if letter == 'A' and not contains_A:
                contains_A = True
        return True
