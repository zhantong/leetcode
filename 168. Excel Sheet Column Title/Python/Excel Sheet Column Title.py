class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = ''
        while n:
            n -= 1
            result = chr(ord('A') + n % 26) + result
            n //= 26
        return result
