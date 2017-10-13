class Solution:
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        min_close = 0
        max_close = 0
        for letter in s:
            if letter == '(':
                min_close += 1
                max_close += 1
            elif letter == ')':
                if min_close > 0:
                    min_close -= 1
                max_close -= 1
                if max_close < 0:
                    return False
            else:
                if min_close > 0:
                    min_close -= 1
                max_close += 1
        return min_close == 0
