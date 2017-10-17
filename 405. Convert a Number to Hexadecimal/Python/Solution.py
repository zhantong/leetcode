class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        symbols = '0123456789abcdef'
        result = ''
        while num:
            value = num & 0xf
            result += symbols[value]
            num = num >> 4 if num > 0 else (num % 0x100000000) >> 4
        return result[::-1]
