class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        def is_water(i, j):
            if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
                return True
            if grid[i][j] == 0:
                return True
            return False

        perimeter = 0
        for (i, row) in enumerate(grid):
            for (j, item) in enumerate(row):
                if item == 1:
                    if is_water(i, j - 1):
                        perimeter += 1
                    if is_water(i - 1, j):
                        perimeter += 1
                    if is_water(i, j + 1):
                        perimeter += 1
                    if is_water(i + 1, j):
                        perimeter += 1
        return perimeter
