class Solution(object):
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 9
        max = 10 ** n - 1
        for i in range(max, max // 10, -1):
            current = int(str(i) + str(i)[::-1])
            for item in range(max, int(math.floor(current ** 0.5)), -1):
                if current % item == 0:
                    return current % 1337
