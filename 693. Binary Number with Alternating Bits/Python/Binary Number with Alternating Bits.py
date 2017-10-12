class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        is_prev_zero = n & 1 == 0
        current = 2
        while n >= current:
            if is_prev_zero == (n & current == 0):
                return False
            is_prev_zero = not is_prev_zero
            current <<= 1
        return True
