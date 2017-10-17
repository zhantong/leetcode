class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        while num % 2 == 0 and num:
            num //= 2
        while num % 3 == 0 and num:
            num //= 3
        while num % 5 == 0 and num:
            num //= 5
        return num == 1
