class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        times = 1
        while times <= n:
            a = n // times
            b = n % times
            if a % 10 == 0:
                result += a // 10 * times
            elif a % 10 == 1:
                result += a // 10 * times + b + 1
            else:
                result += (a // 10 + 1) * times
            times *= 10
        return result
