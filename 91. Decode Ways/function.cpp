#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return recur(s, dp, 0);
    }
    
    int recur(const string &s, vector<int> &dp, const int &index) {
        if (index >= s.length()) return 1;
        else if (s[index] == '0') return 0;
        else if (dp[index] != -1) return dp[index];

        int tmp = recur(s, dp, index+1);
        if (index < s.length()-1 and (s[index]-'0')*10 + (s[index+1]-'0') <= 26) {
            tmp += recur(s, dp, index+2);
        }

        return dp[index] = tmp;
    }
};
