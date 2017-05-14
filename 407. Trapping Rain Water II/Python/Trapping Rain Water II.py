class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap:
            return 0
        heap = []
        m = len(heightMap)
        n = len(heightMap[0])
        for i in range(m):
            heapq.heappush(heap, (heightMap[i][0], i, 0))
            heightMap[i][0] *= -1
            heightMap[i][0] -= 1
            heapq.heappush(heap, (heightMap[i][n - 1], i, n - 1))
            heightMap[i][n - 1] *= -1
            heightMap[i][n - 1] -= 1
        for j in range(1, n - 1):
            heapq.heappush(heap, (heightMap[0][j], 0, j))
            heightMap[0][j] *= -1
            heightMap[0][j] -= 1
            heapq.heappush(heap, (heightMap[m - 1][j], m - 1, j))
            heightMap[m - 1][j] *= -1
            heightMap[m - 1][j] -= 1
        steps = ((-1, 0), (1, 0), (0, -1), (0, 1))
        result = 0
        while heap:
            height, i, j = heapq.heappop(heap)
            for step in steps:
                row = i + step[0]
                col = j + step[1]
                if row >= 0 and col >= 0 and row < m and col < n and heightMap[row][col] >= 0:
                    result += max(0, height - heightMap[row][col])
                    heapq.heappush(heap, (max(height, heightMap[row][col]), row, col))
                    heightMap[row][col] *= -1
                    heightMap[row][col] -= 1
        return result
