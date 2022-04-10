#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        if (numRows == 1) return s;
        
        int row = 0;
        int flag = 1;
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            v[row] += s[i];
            if (flag && row == numRows - 1) flag = 0;
            else if (!flag && row == 0) flag = 1;
            
            if (flag) row += 1;
            else row -= 1;
        }
        for (auto S : v) {
            ans += S;
        }
        
        return ans;
    }
};