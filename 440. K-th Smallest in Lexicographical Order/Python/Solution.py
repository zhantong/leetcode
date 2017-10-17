class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        current = 1
        k -= 1
        while k > 0:
            steps = 0
            start = current
            end = start + 1
            while start <= n:
                steps += min(n + 1, end) - start
                start *= 10
                end *= 10
            if steps <= k:
                current += 1
                k -= steps
            else:
                current *= 10
                k -= 1
        return current
