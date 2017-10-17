class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        all_ones = 1
        while all_ones <= num:
            all_ones <<= 1
        all_ones -= 1
        return all_ones ^ num
