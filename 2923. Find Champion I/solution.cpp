class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans = -1;
        for (int i = 0; i < grid.size() and ans == -1; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 and i != j) break;
                else if (j == grid.size() - 1) {
                    ans = i;
                    break;
                }
            }
        }
        
        return ans;
    }
};
