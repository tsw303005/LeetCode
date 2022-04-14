#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int check(int row, int col, int n) {
        if (row > n || col > n) return false;
        if (row < 1 || col < 1) return false;
        return true;
    }
    
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > m(n, vector<int>(n, 0));
        
        int row = 1;
        int col = 1;
        int dir_r[4] = {0, 1, 0, -1};
        int dir_c[4] = {1, 0, -1, 0};
        int dir = 0;
        int all = n * n;
        
        for (int i = 1; i <= all; i++) {
            m[row-1][col-1] = i;
            if (!check(row + dir_r[dir], col + dir_c[dir], n)) dir = (dir + 1) % 4;
            else if (m[row + dir_r[dir] - 1][col + dir_c[dir] - 1] != 0) dir = (dir + 1) % 4;
            row += dir_r[dir];
            col += dir_c[dir];
        }
        
        return m;
    }
};