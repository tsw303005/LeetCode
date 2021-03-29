#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int row, col;
    bool iddfs(vector<vector<int> >& matrix, vector<vector<bool> >& record, int step, int run, int sr, int sc) {
        if (run > step || sr < 0 || sc < 0 || sr >= row || sc >= col || run + matrix[sr][sc] > step) return false;
        if (record[sr][sc]) return false;
        if (matrix[sr][sc] == 0) return true;
        else {
            record[sr][sc] = true;
            bool flag;
            flag = iddfs(matrix, record, step, run+1, sr-1, sc);
            flag = flag || iddfs(matrix, record, step, run+1, sr+1, sc);
            flag = flag || iddfs(matrix, record, step, run+1, sr, sc-1);
            flag = flag || iddfs(matrix, record, step, run+1, sr, sc+1);
            record[sr][sc] = false;
            if (flag) matrix[sr][sc] = step-run;
            return flag;
        }
    }
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) matrix[i][j] = -1;
            }
        }
        vector<vector<bool> > record(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == -1) {
                    int step = 1;
                    while (true) {
                        if (iddfs(matrix, record, step, 0, i, j)) break;
                        step += 1;
                    }
                    matrix[i][j] = step;
                }
            }
        }
        return matrix;
    }
};