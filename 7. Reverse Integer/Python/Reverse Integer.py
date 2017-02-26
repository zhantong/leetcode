class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = -1 if x < 0 else 1
        x *= sign
        result = 0
        while x:
            result = result * 10 + x % 10
            x //= 10
        if result > 0x7fffffff:
            return 0
        return result * sign
