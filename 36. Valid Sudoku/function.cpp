#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int n = board.size();
        int a, b;
        vector<unordered_set<char> > row(n+1);
        vector<unordered_set<char> > col(n+1);
        vector<unordered_set<char> > block(n+1);
        char c;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a = i / 3;
                b = j / 3;
                c = board[i][j];
                if (c != '.') {
                    if (row[i].find(c) != row[i].end()) return false;
                    else if (col[j].find(c) != col[j].end()) return false;
                    else if (block[a * 3 + b].find(c) != block[a * 3 + b].end()) return false;
                    else {
                        row[i].insert(c);
                        col[j].insert(c);
                        block[a * 3 + b].insert(c);
                    }
                }
            }
        }
        return true;
    }
};