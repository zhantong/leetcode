class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n == 4:
            return 4
        result = 1
        while n > 4:
            n -= 3
            result *= 3
        if n == 4:
            result *= 4
        elif n == 3:
            result *= 3
        elif n == 2:
            result *= 2
        return result
