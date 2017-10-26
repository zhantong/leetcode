class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        def gcd(x, y):
            while y:
                x, y = y, x % y
            return x

        if x + y < z:
            return False
        if x == z or y == z or x + y == z:
            return True
        return z % gcd(x, y) == 0
