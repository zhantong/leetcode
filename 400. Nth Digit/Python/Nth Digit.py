class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        digits = 1
        start = 1
        length = 9
        while (n > digits * length):
            n -= digits * length
            digits += 1
            start *= 10
            length *= 10
        n -= 1
        number = start + n // digits
        return int(str(number)[n % digits])
