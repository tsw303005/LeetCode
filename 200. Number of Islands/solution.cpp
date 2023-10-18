#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        grid[row][col] = '0';
        
        if (row > 0 && grid[row-1][col] == '1')  dfs(row-1, col, grid);
        if (row < grid.size() - 1 && grid[row+1][col] == '1') dfs(row+1, col, grid);
        if (col > 0  && grid[row][col-1] == '1') dfs(row, col-1, grid);
        if (col < grid[0].size() - 1 && grid[row][col+1] == '1') dfs(row, col+1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans += 1;
                    dfs(i, j, grid);
                }
            }
        }
        
        return ans;
    }
};
