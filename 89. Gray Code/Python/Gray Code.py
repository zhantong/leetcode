class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        return [i ^ (i >> 1) for i in range(1 << n)]
