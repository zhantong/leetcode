class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        low = 0
        high = num
        while low <= high:
            mid = (low + high) // 2
            sqar = mid * mid
            if sqar == num:
                return True
            if sqar < num:
                low = mid + 1
            elif sqar > num:
                high = mid - 1
        return False
