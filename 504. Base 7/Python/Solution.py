class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return str(num)
        sign = 1 if num >= 0 else -1
        num = abs(num)
        result = ''
        while num:
            result = str(num % 7) + result
            num //= 7
        return ('-' if sign < 0 else '') + result
