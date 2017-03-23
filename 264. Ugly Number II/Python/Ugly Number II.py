class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        index_2 = -1
        index_3 = -1
        index_5 = -1
        ugly = []
        factor_2 = 1
        factor_3 = 1
        factor_5 = 1
        for i in range(n):
            ugly.append(min(factor_2, factor_3, factor_5))
            if ugly[i] == factor_2:
                index_2 += 1
                factor_2 = ugly[index_2] * 2
            if ugly[i] == factor_3:
                index_3 += 1
                factor_3 = ugly[index_3] * 3
            if ugly[i] == factor_5:
                index_5 += 1
                factor_5 = ugly[index_5] * 5
        return ugly[-1]
