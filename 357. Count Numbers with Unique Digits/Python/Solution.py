class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        map = [None] * (n + 1)
        map[1] = 10
        for i in range(2, n + 1):
            count = 9
            for j in range(9 - i + 2, 10):
                count *= j
            map[i] = map[i - 1] + count
        return map[n]
