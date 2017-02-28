class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        result = 0
        if len(A) < 2:
            return 0
        gap = A[1] - A[0]
        length = 2
        for i in range(2, len(A)):
            if A[i] - A[i - 1] == gap:
                length += 1
            else:
                if length >= 3:
                    result += (1 + length - 3 + 1) * (length - 3 + 1) // 2
                gap = A[i] - A[i - 1]
                length = 2
        if length >= 3:
            result += (1 + length - 3 + 1) * (length - 3 + 1) // 2
        return result
