class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        result = 0
        length = len(A)
        memory = [{} for _ in range(length)]
        for i in range(length):
            for j in range(i):
                diff = A[i] - A[j]
                current = 0
                if diff in memory[j]:
                    result += memory[j][diff]
                    current += memory[j][diff]
                if diff in memory[i]:
                    current += memory[i][diff]
                memory[i][diff] = current + 1
        return result
