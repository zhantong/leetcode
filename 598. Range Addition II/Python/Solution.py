class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        result_m = m
        result_n = n
        for op in ops:
            result_m = min(result_m, op[0])
            result_n = min(result_n, op[1])
        return result_m * result_n
