#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2, vector<int>(n, 1e8));
        bool check;

        for (int i = 0; i < k + 1; i++) {
            dp[i][src] = 0;
            check = false;
            for (auto &e : flights) {
                if(dp[i][e[0]] != 1e8 and dp[i+1][e[1]] > dp[i][e[0]] + e[2]) {
                    check = true;
                    dp[i+1][e[1]] = dp[i][e[0]] + e[2];
                }
            }
            if (!check) {
                return (dp[i+1][dst] == 1e8) ? -1 : dp[i+1][dst];
            }
        }
        
        return (dp[k+1][dst] == 1e8) ? -1 : dp[k+1][dst];
    }
};
