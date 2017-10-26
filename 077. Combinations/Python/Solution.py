class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def comb(result, current, start, n, k):
            if k == 0:
                result.append(current[:])
            else:
                for i in range(start, n + 1):
                    current.append(i)
                    comb(result, current, i + 1, n, k - 1)
                    current.pop()

        result = []
        comb(result, [], 1, n, k)
        return result
