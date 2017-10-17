class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        def is_water(i, j):
            return i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] == 0

        directions = ((0, -1), (0, 1), (-1, 0), (1, 0))
        perimeter = 0
        for (i, row) in enumerate(grid):
            for (j, item) in enumerate(row):
                if item == 1:
                    for direction in directions:
                        if is_water(i + direction[0], j + direction[1]):
                            perimeter += 1
        return perimeter
