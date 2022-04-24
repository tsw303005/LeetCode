#include <iostream>

using namespace std;

class Solution {
public:
    int ans;
    int m[20];
    
    bool judge(int row, int col, int n) {
        for (int i = 1; i <= n; i++) {
            if (m[i] != 0 and abs(i - col) == abs(m[i] - row)) {
                return false;
            }
        }
            
        return true;
    }
    
    void recur(int layer, int n) {
        if (layer == n + 1) {
            ans += 1;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (m[i] == 0 and judge(layer, i, n)) {
                m[i] = layer;
                recur(layer+1, n);
                m[i] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        recur(1, n);
        
        return ans;
    }
};
