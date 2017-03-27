class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        the_sum = sum(A)
        F = sum([index * item for index, item in enumerate(A)])
        current_max = F
        length = len(A)
        for i in range(1, length):
            F += the_sum - length * A[length - i]
            current_max = max(current_max, F)
        return current_max
