class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        i = 5
        while i <= n:
            result += n // i
            i *= 5
        return result
