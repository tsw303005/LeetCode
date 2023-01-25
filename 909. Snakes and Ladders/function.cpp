#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        vector<bool> record(board.size() * board.size() + 1, false);
        int size = board.size() * board.size();
        int row, col;
        int ans = 0;
        
        q.push(1);
        record[1] = true;
            
        while (!q.empty()) {
            int num = q.size();
            for (int i = 0; i < num; i++) {
                auto now = q.front();
                q.pop();
                
                if (now == size) return ans;
                
                for (int j = now + 1; j <= now + 6 and j <= size; j++) {
                    if (record[j]) {
                        continue;
                    }
                    row = (board.size() - 1) - (j - 1) / board.size();
                    col = ((board.size() - 1 - row) % 2 == 1) ? board.size() - 1 - (j - 1) % board.size() : (j-1) % board.size();

                    if (board[row][col] == -1) q.push(j);
                    else q.push(board[row][col]);
                    record[j] = true;
                }
            }
            ans += 1;
        }
        
        return -1;
    }
};
