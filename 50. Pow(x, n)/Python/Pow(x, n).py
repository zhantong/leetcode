class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if not n:
            return 1
        if n < 0:
            n = -n
            x = 1 / x
        if n % 2:
            return x * self.myPow(x * x, n // 2)
        return self.myPow(x * x, n // 2)
