class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        results = [0] * (n + 1)
        results[0] = 1
        for i in range(1, n + 1):
            for j in range(i):
                results[i] += results[j] * results[i - j - 1]
        return results[n]
