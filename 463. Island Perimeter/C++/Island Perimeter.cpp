class Solution {
public:
    int islandPerimeter(vector <vector<int>> &grid) {
        auto isWater = [&grid](int i, int j) {
            return i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0;
        };
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    if (isWater(i, j - 1)) {
                        perimeter++;
                    }
                    if (isWater(i - 1, j)) {
                        perimeter++;
                    }
                    if (isWater(i, j + 1)) {
                        perimeter++;
                    }
                    if (isWater(i + 1, j)) {
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};