class Solution {
public:
    queue<pair<int, int>> q;
    vector<int> move = {-1, 0, 1, 0};

    void runBFS(const vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int rows = grid.size();
        int cols = grid[0].size();
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i <= 3; i++) {
                int newX = x + move[i], newY = y + move[3 - i];
                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols &&
                    !vis[newX][newY] && grid[newX][newY] == '1') {
                    q.push({newX, newY});
                    vis[newX][newY] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int cnt = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    q.push({i, j});
                    vis[i][j] = true;
                    cnt++;
                    runBFS(grid, vis);
                }
            }
        }
        return cnt;
    }
};