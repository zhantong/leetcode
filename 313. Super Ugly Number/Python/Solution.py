class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        factors = [1] * len(primes)
        indexes = [-1] * len(primes)
        ugly = [None] * n
        for i in range(n):
            ugly[i] = min(factors)
            for j, factor in enumerate(factors):
                if ugly[i] == factor:
                    indexes[j] += 1
                    factors[j] = ugly[indexes[j]] * primes[j]
        return ugly[-1]
