class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        count = 0
        xor = x ^ y
        while xor != 0:
            xor &= (xor - 1)
            count += 1
        return count
