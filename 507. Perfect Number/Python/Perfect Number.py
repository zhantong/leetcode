class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1:
            return False
        result = 0
        i = 2
        while i * i <= num:
            if num % i == 0:
                result += i
                result += num // i
            i += 1
        result += 1
        return result == num
