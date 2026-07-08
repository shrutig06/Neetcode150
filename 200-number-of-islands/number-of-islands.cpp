class Solution {
public:
    vector<int> move={-1, 1, 0, 0};
    void callBFS(queue<pair<int,int>>& q, vector<vector<char>>& grid){
        int row=grid.size(), col=grid[0].size();
       
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=it.first+move[i], y=it.second+move[3-i];
                if(x>=0 && x<row && y>=0 && y<col && grid[x][y]=='1'){
                    grid[x][y]='2';
                    q.push({x,y});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    q.push({i,j});
                    grid[i][j]='2';
                    callBFS(q, grid);
                }
            }
        }

        return cnt;
    }
};