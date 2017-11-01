class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        last = n & 1
        while n != 0 and n & 1 == last:
            last = 1 - last
            n >>= 1
        return n == 0
