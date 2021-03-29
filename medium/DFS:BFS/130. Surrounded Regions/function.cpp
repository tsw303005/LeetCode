#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int row, col;
    void dfs(vector<vector<char> >& board, int sr, int sc) {
        if (board[sr][sc] == 'z') return ;
        board[sr][sc] = 'z';
        if (sr-1 >= 0 && board[sr-1][sc] == 'O') dfs(board, sr-1, sc);
        if (sr+1 < row && board[sr+1][sc] == 'O') dfs(board, sr+1, sc);
        if (sc-1 >= 0 && board[sr][sc-1] == 'O') dfs(board, sr, sc-1);
        if (sc+1 < col && board[sr][sc+1] == 'O') dfs(board, sr, sc+1);
    }
    void solve(vector<vector<char> >& board) {
        row = board.size();
        col = board[0].size();
        if (row == 0 || col == 0) return ;
        
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][col-1] == 'O') dfs(board, i, col-1);
        }
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[row-1][i] == 'O') dfs(board, row-1, i);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'z') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};