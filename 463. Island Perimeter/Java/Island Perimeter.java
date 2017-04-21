public class Solution {
    public int islandPerimeter(int[][] grid) {
        class Utils {
            boolean isWater(int i, int j) {
                return i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == 0;
            }
        }
        Utils utils = new Utils();
        int[][] directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int perimeter = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    for (int[] direction : directions) {
                        if (utils.isWater(i + direction[0], j + direction[1])) {
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
}