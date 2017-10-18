# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):


class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        while low <= high:
            mid = (low + high) // 2
            guess_result = guess(mid)
            if guess_result == 0:
                return mid
            if guess_result == 1:
                low = mid + 1
            else:
                high = mid - 1
