class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        factor = [0] * n
        factor[0] = 1
        for i in range(1, n):
            factor[i] = factor[i - 1] * i
        result = ''
        k -= 1
        numbers = [i for i in range(1, 10)]
        for i in range(n - 1, -1, -1):
            number = k // factor[i]
            k %= factor[i]
            result += str(numbers[number])
            del numbers[number]
        return result
