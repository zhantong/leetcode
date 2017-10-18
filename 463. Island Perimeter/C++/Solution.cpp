class Solution {
public:
    int islandPerimeter(vector <vector<int>> &grid) {
        auto isWater = [&grid](int i, int j) {
            return i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0;
        };
        vector <vector<int>> directions{{0,  -1}, {0,  1}, {-1, 0}, {1,  0}};
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    for (auto &direction : directions) {
                        if (isWater(i + direction[0], j + direction[1])) {
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};