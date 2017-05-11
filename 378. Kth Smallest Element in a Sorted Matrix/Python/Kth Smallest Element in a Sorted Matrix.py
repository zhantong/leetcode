class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        m = len(matrix)
        n = len(matrix[0])
        min_heap = []
        for j in range(n):
            heapq.heappush(min_heap, (matrix[0][j], 0, j))
        while min_heap:
            current, i, j = heapq.heappop(min_heap)
            if i < m - 1:
                heapq.heappush(min_heap, (matrix[i + 1][j], i + 1, j))
            k -= 1
            if k == 0:
                return current
