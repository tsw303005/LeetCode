#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<int> m;
    
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
            vector<string> result;
            for (int i = 1; i <= n; i++) {
                string s(n, '.');
                for (int j = 1; j <= n; j++) {
                    if (m[j] == i) s[j - 1] = 'Q';
                }
                result.push_back(s);
            }
            ans.push_back(result);
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
    
    vector<vector<string>> solveNQueens(int n) {
        m.resize(n + 1);
        fill(m.begin(), m.end(), 0);
        
        recur(1, n);
        return ans;
    }
};
