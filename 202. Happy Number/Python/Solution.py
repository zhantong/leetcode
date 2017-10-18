class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        got = set()
        while n != 1 and n not in got:
            got.add(n)
            sum = 0
            while n:
                sum += (n % 10)**2
                n //= 10
            n = sum

        return n == 1
