class Solution {
public:
    void runDFS(vector<vector<int>>& grid, int x, int y, int& rows, int& cols, int& area){
        if(x>=0 && x<rows && y-1>=0 && y<cols && grid[x][y-1]==1){
            area++;
            grid[x][y-1]=2;
            runDFS(grid, x, y-1, rows, cols, area);
        }
        if(x>=0 && x<rows && y>=0 && y+1<cols && grid[x][y+1]==1){
            area++;
            grid[x][y+1]=2;
            runDFS(grid, x, y+1, rows, cols, area);
        }
        if(x-1>=0 && x<rows && y>=0 && y<cols && grid[x-1][y]==1){
            area++;
            grid[x-1][y]=2;
            runDFS(grid, x-1, y, rows, cols, area);
        }
        if(x+1<rows && x>=0 && y>=0 && y<cols && grid[x+1][y]==1){
            area++;
            grid[x+1][y]=2;
            runDFS(grid, x+1, y, rows, cols, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxArea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int area=1;
                    grid[i][j]=2;
                    runDFS(grid, i, j, rows, cols, area);
                    maxArea=max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};