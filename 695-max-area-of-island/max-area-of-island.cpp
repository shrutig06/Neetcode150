class Solution {
public:
    void runDFS(vector<vector<int>>& grid, int x, int y, int& area) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] != 1)
            return;
        grid[x][y] = 2;
        area++;
        runDFS(grid, x, y - 1, area);
        runDFS(grid, x, y + 1, area);
        runDFS(grid, x - 1, y, area);
        runDFS(grid, x + 1, y, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    runDFS(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};