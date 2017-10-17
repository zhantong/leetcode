class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        queue = collections.deque()
        m = len(matrix)
        n = len(matrix[0])
        MAX_VALUE = m + n
        for i, row in enumerate(matrix):
            for j, item in enumerate(row):
                if item:
                    row[j] = MAX_VALUE
                else:
                    queue.append((i, j))
        current = 1
        while queue:
            size = len(queue)
            for _ in range(size):
                i, j = queue.popleft()
                if i > 0 and matrix[i - 1][j] == MAX_VALUE:
                    matrix[i - 1][j] = current
                    queue.append((i - 1, j))
                if i < m - 1 and matrix[i + 1][j] == MAX_VALUE:
                    matrix[i + 1][j] = current
                    queue.append((i + 1, j))
                if j > 0 and matrix[i][j - 1] == MAX_VALUE:
                    matrix[i][j - 1] = current
                    queue.append((i, j - 1))
                if j < n - 1 and matrix[i][j + 1] == MAX_VALUE:
                    matrix[i][j + 1] = current
                    queue.append((i, j + 1))
            current += 1
        return matrix
