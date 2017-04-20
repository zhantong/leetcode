class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = (dividend > 0) == (divisor > 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        a = dividend
        b = divisor
        result = 0
        current = 1
        while a >= divisor:
            a -= b
            result += current
            current += current
            b += b
            if a < b:
                b = divisor
                current = 1
        if sign:
            return min(result, 2147483647)
        else:
            return max(-result, -2147483648)
