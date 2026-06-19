class Solution {
public:
    int runDFS(vector<vector<int>>& grid, int x, int y) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] != 1)
            return 0;
        grid[x][y] = 2;
        return 1 + runDFS(grid, x, y - 1) + runDFS(grid, x, y + 1) +
               runDFS(grid, x - 1, y) + runDFS(grid, x + 1, y);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, runDFS(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};