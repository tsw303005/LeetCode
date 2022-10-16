#include <vector>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        
        int n = jobDifficulty.size();
        vector<vector<int>> dp(d+1, vector<int>(n+1, INT_MAX));
        dp[1][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[1][i] = max(dp[1][i-1], jobDifficulty[i-1]);
        }
        
        for (int i = 2; i <= d; i++) {
            for (int j = i; j <= n; j++) {
                int m = jobDifficulty[j-1];
                for (int k = j - 1; k >= i - 1; k--) {
                    m = max(m, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + m);
                }
            }
        }
        
        return dp[d][n];
    }
};
