class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 3
        if n == 0:
            return 0
        counts = [0] * (n + 1)
        counts[0] = 1
        counts[1] = 2
        counts[2] = 4
        MOD = 10 ** 9 + 7
        for i in range(3, n + 1):
            counts[i] = (counts[i - 1] + counts[i - 2] + counts[i - 3]) % MOD
        result = counts[-1]
        for i in range(1, n + 1):
            result += (counts[i - 1] * counts[n - i]) % MOD
            result %= MOD
        return result
