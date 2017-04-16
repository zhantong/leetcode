class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        m = len(matrix)
        n = len(matrix[0])
        result = -sys.maxsize
        for col_start in range(n):
            current = [0] * m
            for col_end in range(col_start, n):
                for i in range(m):
                    current[i] += matrix[i][col_end]
                sums = [0]
                current_sum = 0
                for i, item in enumerate(current):
                    current_sum += item
                    target = current_sum - k
                    low = 0
                    high = len(sums) - 1
                    while low <= high:
                        mid = (low + high) // 2
                        if sums[mid] < target:
                            low = mid + 1
                        elif sums[mid] > target:
                            high = mid - 1
                        else:
                            low = mid
                            break
                    if low < len(sums) and sums[low] >= target:
                        result = max(result, current_sum - sums[low])
                    sums.append(current_sum)
                    i = 0
                    while sums[i] < current_sum:
                        i += 1
                    sums.insert(i, current_sum)
        return result
