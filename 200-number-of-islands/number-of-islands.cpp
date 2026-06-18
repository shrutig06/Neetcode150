class Solution {
public:
    queue<pair<int, int>> q;
    vector<int> move = {-1, 0, 1, 0};

    void runBFS(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';
                    cnt++;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int i = 0; i <= 3; i++) {
                            int newX = x + move[i], newY = y + move[3 - i];
                            if (newX >= 0 && newY >= 0 && newX < rows &&
                                newY < cols && grid[newX][newY] == '1') {
                                q.push({newX, newY});
                                grid[newX][newY] = '0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};