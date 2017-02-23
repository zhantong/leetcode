class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        low = 1
        high = x
        while low <= high:
            mid = (low + high) // 2
            if mid <= x / mid:
                low = mid + 1
            else:
                high = mid - 1
        return low - 1
